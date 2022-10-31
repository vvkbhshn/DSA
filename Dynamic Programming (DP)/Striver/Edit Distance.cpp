//problem link: https://leetcode.com/problems/edit-distance/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length(), n=word2.length();
        vector<int> dp(n+1);
        for(int j=0;j<=n;j++) dp[j]=j;
        for(int i=1;i<=m;i++){
            int prev2=0, prev=dp[0];
            dp[0]=i;
            for(int j=1;j<=n;j++){
                prev2=prev;
                prev=dp[j];
                if(word1[i-1]==word2[j-1]) dp[j]=prev2;
                else dp[j]=1+min(prev2,min(dp[j-1],dp[j]));
            }
        }
        return dp[n];
    }
};