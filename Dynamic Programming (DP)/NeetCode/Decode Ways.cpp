//problem link: https://leetcode.com/problems/decode-ways/

class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        int n=s.length();
        vector<int> dp(n+1,0);
        dp[0]=dp[1]=1;
        for(int i=1;i<n;i++){
            if(s[i]>='1' && s[i]<='9') dp[i+1]+=dp[i];
            if((s[i-1]=='1') || (s[i-1]=='2' && (s[i]>='0' && s[i]<='6'))) dp[i+1]+=dp[i-1];
        }
        return dp[n];
    }
};