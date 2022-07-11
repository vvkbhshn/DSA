//problem link: https://leetcode.com/problems/unique-binary-search-trees/

class Solution {
public:    
    int count(int n, vector<int> &dp){
        if(n<=1) return 1;
        if(dp[n]!=-1) return dp[n];
        int res=0;
        for(int i=1;i<=n;i++) res+=count(i-1,dp)*count(n-i,dp);
        return dp[n]=res;
    }
    
    int numTrees(int n) {
        vector<int> dp(n+1,-1);
        return count(n,dp);
    }
};