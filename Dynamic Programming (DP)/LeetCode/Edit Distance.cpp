//problem link: https://leetcode.com/problems/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length(), n=word2.length();
        
        // Method-1:
        vector<int> prev(n+1), dp(n+1);
        for(int i=0;i<=n;i++) prev[i]=i;
        for(int i=1;i<=m;i++){
            dp[0]=i;
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]) dp[j]=prev[j-1];
                else dp[j]=1+min(dp[j-1],min(prev[j],prev[j-1]));
            }
            prev=dp;
        }
        return prev[n];
        
        
        // Method-2:
        // vector<vector<int>> dp(m+1,vector<int>(n+1));
        // for(int i=0;i<=n;i++) dp[0][i]=i;
        // for(int i=1;i<=m;i++) dp[i][0]=i;
        // for(int i=1;i<=m;i++){
        //     for(int j=1;j<=n;j++){
        //         if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
        //         else dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
        //     }
        // }
        // return dp[m][n];
    }
};