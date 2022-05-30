//problem link: https://leetcode.com/problems/combinations/

class Solution {
public:
    void findCombinations(vector<vector<int>> &res, vector<int> &temp, int n, int k, int curr){     
        if(k==0){
            res.push_back(temp);
            return;
        }
        for(int i=curr;i<=n;i++){
            temp.push_back(i);
            findCombinations(res,temp,n,k-1,i+1);
            temp.pop_back();
        }        
    }    
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        findCombinations(res,temp,n,k,1);
        return res;
    }
};