//problem link: https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628

int countPartitions(int n, int diff, vector<int> &arr) {
    int sum=0, mod=1e9+7;
    for(auto x:arr) sum+=x;
    if(sum<diff || (sum-diff)%2==1) return 0;
    int k=(sum-diff)/2;
    vector<int> dp(k+1,0);
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=k;j>=arr[i];j--) dp[j]=(dp[j]+dp[j-arr[i]])%mod;
    }
    return dp[k];
}