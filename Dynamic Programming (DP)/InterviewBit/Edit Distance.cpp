//problem link: https://www.interviewbit.com/problems/edit-distance/

int Solution::minDistance(string A, string B) {
    int m=A.length(), n=B.length();
    vector<int> dp(n+1);
    for(int i=0;i<=n;i++) dp[i]=i;
    for(int i=1;i<=m;i++){
        int prev[2]={0,dp[0]};
        dp[0]=i;
        for(int j=1;j<=n;j++){
            swap(prev[0],prev[1]);
            prev[1]=dp[j];
            if(A[i-1]==B[j-1]) dp[j]=prev[0];
            else dp[j]=1+min(prev[0],min(dp[j-1],dp[j]));
        }
    }
    return dp[n];
}
