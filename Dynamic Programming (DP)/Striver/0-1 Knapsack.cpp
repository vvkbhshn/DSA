//problem link: https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){
	vector<int> dp(maxWeight+1,0);
    for(int i=0;i<n;i++){
        for(int j=maxWeight; j>=weight[i]; j--){
            dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }
    return dp[maxWeight];
}