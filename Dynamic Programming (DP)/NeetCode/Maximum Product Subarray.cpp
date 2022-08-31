//problem link: https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int currMax=nums[0], currMin=nums[0], res=nums[0];
        for(int i=1;i<n;i++){
            int temp=currMax;
            currMax=max(nums[i],max(currMax*nums[i],currMin*nums[i]));
            currMin=min(nums[i],min(temp*nums[i],currMin*nums[i]));
            res=max(res,currMax);
        }
        return res;
    }
};