//problem link: https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1
    
int longestCommonSubstr (string S1, string S2, int n, int m)    {
	int res=0;
	vector<int> dp(m+1,0);
	for(int i=1;i<=n;i++){
		int prev=0, prev2=0;
		for(int j=1;j<=m;j++){
			prev2=prev;
			prev=dp[j];
			if(S1[i-1]==S2[j-1]){
				dp[j]=1+prev2;
				res=max(res,dp[j]);
			}
			else dp[j]=0;
		}
	}
	return res;
}