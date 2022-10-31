//problem link: https://leetcode.com/problems/target-sum/

class Solution {
public:    
    // int solve(vector<int> &nums, vector<vector<int>> &dp, int n, int k){
    //     if(n==0){
    //         if(k==0) return 1;
    //         else return 0;
    //     }
    //     if(dp[n][k]!=-1) return dp[n][k];
    //     int res=solve(nums,dp,n-1,k);
    //     if(k>=nums[n-1]) res+=solve(nums,dp,n-1,k-nums[n-1]);
    //     return dp[n][k]=res;
    // }    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(auto x:nums) sum+=x;
        if(target>sum || (sum-target)%2==1) return 0;
        int k=(sum-target)/2;
        
        //Method-1: bottom-up
        vector<int> dp(k+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=k;j>=nums[i];j--){
                dp[j]+=dp[j-nums[i]];
            }
        }
        return dp[k];
        
        //Method-2:top-down
        // vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        // return solve(nums,dp,n,k);
    }
};