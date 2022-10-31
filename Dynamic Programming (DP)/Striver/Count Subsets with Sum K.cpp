//problem link: https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532

int findWays(vector<int> &arr, int k){
    int n=arr.size();
    vector<int> dp(k+1,0);
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=k;j>=arr[i];j--){
            dp[j]+=dp[j-arr[i]];
        }
    }
    return dp[k];
}