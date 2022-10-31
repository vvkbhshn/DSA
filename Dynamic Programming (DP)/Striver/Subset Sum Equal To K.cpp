//problem link: https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(2,vector<bool>(k+1,false));
    dp[0][0]=dp[1][0]=true;
    int curr=1, prev=0;
    for(int i=0;i<n;i++){
        for(int j=1;j<=k;j++){
            dp[curr][j]=dp[prev][j];
            if(j>=arr[i]) dp[curr][j] = dp[curr][j] || dp[prev][j-arr[i]];
        }
        swap(curr,prev);
    }
    return dp[prev][k];
}