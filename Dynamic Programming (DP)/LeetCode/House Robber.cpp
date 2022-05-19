//problem link: https://leetcode.com/problems/house-robber/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int steal=nums[0], skip=0;
        int res=nums[0];
        for(int i=1;i<n;i++){
            //robber has two choices, either to skip the house or steal it
            //if he chose to skip it => amount = steal (total amount stolen till previous house)
            //if he chose to steal it, then he must've skipped the previous house => amount = skip+nums[i]
            int temp=max(steal,skip+nums[i]);
            skip=steal;
            steal=temp;
        }
        return steal;
    }
};