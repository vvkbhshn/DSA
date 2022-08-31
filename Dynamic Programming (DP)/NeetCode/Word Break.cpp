//problem link: https://leetcode.com/problems/word-break/

class Solution {
public:    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        bool dp[n+1];
        dp[0]=true;
        for(int i=1;i<=n;i++){
            dp[i]=false;
            for(int j=i-1;j>=0;j--){
                if(dp[j] && dict.find(s.substr(j,i-j))!=dict.end()){
                    dp[i]=true;
                    break;
                }
            }
        }        
        return dp[n];
    }
};