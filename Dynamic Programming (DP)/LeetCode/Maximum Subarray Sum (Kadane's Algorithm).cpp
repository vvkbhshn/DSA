//problem link: https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currMax=0, totalMax=INT_MIN;
        for(int i=0;i<nums.size();i++){
            currMax+=nums[i];
            if(currMax>totalMax) totalMax=currMax;
            if(currMax<0) currMax=0;
        }
        return totalMax;
    }
};