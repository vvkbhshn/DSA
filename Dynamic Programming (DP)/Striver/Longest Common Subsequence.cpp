//problem link: https://leetcode.com/problems/longest-common-subsequence/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length(), n=text2.length();
        vector<int> dp(n+1,0);        
        for(int i=1;i<=m;i++){
            int prev=0, prev2=0;
            for(int j=1;j<=n;j++){
                prev2=prev;
                prev=dp[j];
                if(text1[i-1]==text2[j-1]) dp[j]=1+prev2;
                else dp[j]=max(dp[j-1],dp[j]);
            }
        }
        return dp[n];
    }
};