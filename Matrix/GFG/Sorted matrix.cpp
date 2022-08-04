//problem link: https://practice.geeksforgeeks.org/problems/sorted-matrix2333/1

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        // code here
        vector<int> elements;
        for(auto r:Mat) for(auto x:r) elements.push_back(x);
        sort(elements.begin(),elements.end());
        vector<vector<int>> res;
        vector<int> temp;
        for(auto x:elements){
            temp.push_back(x);
            if(temp.size()==N){
                res.push_back(temp);
                temp.clear();
            }
        }
        return res;
    }
};