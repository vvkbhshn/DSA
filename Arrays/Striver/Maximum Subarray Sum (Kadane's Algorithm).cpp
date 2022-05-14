//problem link: https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=nums[0], curr=0;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            res=max(res,curr);
            if(curr<0) curr=0;
        }
        return res;
    }
};