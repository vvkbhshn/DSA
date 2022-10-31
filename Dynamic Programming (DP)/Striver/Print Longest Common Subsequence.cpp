//problem link: https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem

vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {
    int m=a.size(), n=b.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    vector<int> res(dp[m][n]);
    int i=m, j=n, index=dp[m][n]-1;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            res[index--]=a[i-1];
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        }
    }
    return res;
}