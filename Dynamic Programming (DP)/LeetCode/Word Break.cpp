//problem link: https://leetcode.com/problems/word-break/

class Solution {
public:
    bool solve(string s, vector<string> &dict, unordered_set<string> &st, vector<int> &dp, int idx){
        int n=s.length();
        if(dp[idx]!=-1) return (bool)dp[idx];
        if(idx==n) return dp[idx]=1;        
        bool res=false;
        for(int i=1;i<=20 && idx+i<=n;i++){
            if(st.find(s.substr(idx,i))!=st.end()){
                bool temp = solve(s,dict,st,dp,idx+i);
                res= res || temp;
            }
        }
        return dp[idx]=res;
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        vector<int> dp(s.length()+1,-1);
        return solve(s,wordDict,st,dp,0);
    }
};