//problem link: https://www.interviewbit.com/problems/longest-common-subsequence/

int Solution::solve(string A, string B) {
    int m=A.length(), n=B.length();
    vector<int> dp(n+1,0);    
    for(int i=1;i<=m;i++){
        int prev[2]={0};
        for(int j=1;j<=n;j++){
            swap(prev[0],prev[1]);
            prev[1]=dp[j];
            if(A[i-1]==B[j-1]) dp[j]=1+prev[0];
            else dp[j]=max(dp[j],dp[j-1]);
        }
    }
    return dp[n];
}
