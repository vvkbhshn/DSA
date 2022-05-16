//problem link: https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        if(numRows==1) return res;
        res.push_back({1,1});
        if(numRows==2) return res;
        for(int i=3;i<=numRows;i++){
            vector<int> temp(i,1);
            for(int j=1;j<res.back().size();j++){
                temp[j]=res.back()[j]+res.back()[j-1];
            }
            res.push_back(temp);
        }
        return res;
    }
};