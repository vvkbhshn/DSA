//problem link: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

class Solution {
public:    
    int longestCommonSubsequence(string s, string t){
        int n=s.length();
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            int prev=0, prev2=0;
            for(int j=1;j<=n;j++){
                prev2=prev;
                prev=dp[j];
                if(s[i-1]==t[j-1]) dp[j]=1+prev2;
                else dp[j]=max(dp[j-1],dp[j]);
            }
        }
        return dp[n];
    }    
    
    int longestPalindromeSubsequence(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        return longestCommonSubsequence(s,t);
    }
    
    int minInsertions(string s) {
        int n=s.length();
        return n-longestPalindromeSubsequence(s);
    }
};