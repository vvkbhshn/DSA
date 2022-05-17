// problem link: https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) { 
        // DP solution: O(amount) space
        int n=coins.size();
        int dp[amount+1];
        dp[0]=0;
        sort(coins.begin(),coins.end());
        for(int i=1;i<=amount;i++){
            dp[i]=INT_MAX-1;
            for(auto x:coins){
                if(x>i) break;
                dp[i]=min(dp[i],1+dp[i-x]);
            }
        }
        return dp[amount]==INT_MAX-1 ? -1 : dp[amount];
        
        
        
        // Unbounded Knapsack
        // DP solution: O(amount) space
        // int n=coins.size();
        // vector<int> dp(amount+1);
        // dp[0]=0;
        // for(int i=1;i<=amount;i++) dp[i]=INT_MAX-1;
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=amount;j++){
        //         if(coins[i-1]<=j) dp[j]=min(dp[j],1+dp[j-coins[i-1]]);
        //     }
        // }
        // return dp[amount]==INT_MAX-1 ? -1 : dp[amount];
        
        // DP solution: O(n*amount) space
        // int dp[n+1][amount+1];
        // for(int i=0;i<=n;i++) dp[i][0]=0;
        // for(int i=1;i<=amount;i++) dp[0][i]=INT_MAX-1;
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=amount;j++){
        //         if(coins[i-1]<=j) dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
        //         else dp[i][j]=dp[i-1][j];
        //     }
        // }
        // return dp[n][amount]==INT_MAX-1 ? -1 : dp[n][amount];
    }
};