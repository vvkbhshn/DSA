//problem link: https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto x:nums) sum+=x;
        if(sum&1) return false;
        sum/=2;
        vector<bool> dp(sum+1,false);
        dp[0]=true;
        for(int i=0;i<n;i++){
            for(int j=sum;j>=nums[i];j--){
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
        return dp[sum];
    }
};