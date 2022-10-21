//problem link: https://www.interviewbit.com/problems/longest-palindromic-subsequence/

int Solution::solve(string A) {
    int n=A.length();
    vector<int> dp(n+1,0);
    for(int i=1;i<=n;i++){
        int prev[2]={0};
        for(int j=1;j<=n;j++){
            swap(prev[0],prev[1]);
            prev[1]=dp[j];
            if(A[i-1]==A[n-j]) dp[j]=1+prev[0];
            else dp[j]=max(dp[j],dp[j-1]);
        }
    }
    return dp[n];
}