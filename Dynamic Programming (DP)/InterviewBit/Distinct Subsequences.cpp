//problem link: https://www.interviewbit.com/problems/distinct-subsequences/

int Solution::numDistinct(string A, string B) {
    int m=A.length(), n=B.length();
    vector<int> dp(m+1,1);
    for(int i=1;i<=n;i++){
        int prev[2]={0,dp[0]};
		dp[0]=0;
        for(int j=1;j<=m;j++){
            //logic:
            //if(B[i-1]==A[j-1]) dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
            //else dp[i][j]=dp[i][j-1];                        
            swap(prev[0],prev[1]);
            prev[1]=dp[j];
            if(B[i-1]==A[j-1]) dp[j]=dp[j-1]+prev[0];
            else dp[j]=dp[j-1];
        }
    }
    return dp[m];
}
