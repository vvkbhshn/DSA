//problem link: https://practice.geeksforgeeks.org/problems/number-of-coins1824/1#

// The GREEDY approach can be to always pick the largest possible value coin such that coins[i]<=V,
// then V-=coins[i]. But this approach will not always work. eg. V=12, coins[]={9,6,1}
// however, this can work suppose when coins[]={ 1, 2, 5, 10, 20, 50, 100, 500, 1000}

// So, we have to solve this problem by Dynamic Programming using the concept of Unbounded Knapsack.

int minCoins(int coins[], int M, int V) 
{ 
    // Your code goes here
    vector<int> dp(V+1,INT_MAX-1);
    dp[0]=0;
    for(int i=1;i<=M;i++){
        for(int j=1;j<=V;j++){
            if(coins[i-1]<=j){
                dp[j]=min(dp[j],1+dp[j-coins[i-1]]);
            }
        }
    }
    return dp[V]==INT_MAX-1 ? -1: dp[V];
}