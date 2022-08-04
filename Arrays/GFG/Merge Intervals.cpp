//problem link: https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        for(auto v:intervals){
            if(res.empty() || v[0]>res.back()[1]) res.push_back(v);  
            else res.back()[1]=max(res.back()[1],v[1]);
        }
        return res;
    }
};