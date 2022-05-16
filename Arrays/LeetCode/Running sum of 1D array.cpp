//problem link: https://leetcode.com/problems/running-sum-of-1d-array/

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res;
        int temp=0;
        for(auto x:nums){
            temp+=x;
            res.push_back(temp);
        }
        return res;
    }
};