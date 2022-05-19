//problem link: https://leetcode.com/problems/maximum-length-of-repeated-subarray/

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(), n=nums2.size();
        
        // Method-1: DP [O(n) space]
        int res=0;
        vector<int> dp(n+1), preDP(n+1);
        preDP[0]=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(nums1[i-1]==nums2[j-1]) dp[j]=1+preDP[j-1];
                else dp[j]=0;
                res=max(res, dp[j]);
            }
            preDP=dp;
        }
        return res;
        
        // Method-2: DP [O(m*n) space]
        // int res=0;
        // int dp[m+1][n+1];
        // memset(dp,0,sizeof(dp));
        // for(int i=1;i<=m;i++){
        //     for(int j=1;j<=n;j++){
        //         if(nums1[i-1]==nums2[j-1]){
        //             dp[i][j]=1+dp[i-1][j-1];
        //             res=max(res,dp[i][j]);
        //         }                
        //     }
        // }
        // return res;
    }
};