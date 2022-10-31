//problem link: https://practice.geeksforgeeks.org/problems/rod-cutting0840/1

class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<int> dp(n+1,0);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=n;j++){
                dp[j]=max(dp[j],price[i]+dp[j-(i+1)]);
            }
        }
        return dp[n];
    }
};