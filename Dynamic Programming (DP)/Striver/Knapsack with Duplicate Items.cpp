//problem link: https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])    {
        vector<int> dp(W+1,0);
        for(int i=0;i<N;i++){
            for(int j=wt[i];j<=W;j++){
                dp[j]=max(dp[j],val[i]+dp[j-wt[i]]);
            }
        }
        return dp[W];
    }
};