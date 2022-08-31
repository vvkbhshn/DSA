//problem link: https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();       
        const int sz=amount+1;
        int dp[sz];
        dp[0]=0;
        for(int j=1;j<=amount;j++) dp[j]=INT_MAX-1;
        for(int i=0;i<n;i++){
            for(int j=coins[i];j<=amount;j++){
                dp[j]=min(1+dp[j-coins[i]],dp[j]);
            }
        }
        if(dp[amount]==INT_MAX-1) return -1;
        return dp[amount];
    }
};