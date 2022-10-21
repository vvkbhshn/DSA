//problem link: https://www.interviewbit.com/problems/repeating-subsequence/

int Solution::anytwo(string A) {
    int n=A.length();
    vector<int> dp(n+1,0);
    for(int i=1;i<=n;i++){
        int prev[2]={0};
        for(int j=1;j<=n;j++){
            swap(prev[0],prev[1]);
            prev[1]=dp[j];
            if(A[i-1]==A[j-1] && i!=j) dp[j]=1+prev[0];
            else dp[j]=max(dp[j-1],dp[j]);
        }
    }
    return dp[n]>1?1:0;
}