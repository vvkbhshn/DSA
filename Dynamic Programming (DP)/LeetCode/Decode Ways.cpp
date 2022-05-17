//problem link: https://leetcode.com/problems/decode-ways/

class Solution {
public:
    int solve(string &s, int dp[], int i){
        if(dp[i]!=-1) return dp[i];
        if(s[i]=='0') return dp[i]=0;
        int res=solve(s,dp,i+1);
        if(i<s.length()-1 && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))) res+=solve(s,dp,i+2);         return dp[i]=res;
    }
    
    int numDecodings(string s) {
        int n=s.length();
        int dp[101];
        memset(dp,-1,sizeof(dp));
        dp[n]=1;
        return solve(s,dp,0);
    }
};