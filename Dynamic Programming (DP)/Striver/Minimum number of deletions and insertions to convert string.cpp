//problem link: https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1
	
	// int solve(string &str1, string &str2, vector<vector<int>> &dp, int m, int n){
	//     if(m==0) return n;
	//     if(n==0) return m;
	//     if(dp[m][n]!=-1) return dp[m][n];
	//     int res=0;
	//     if(str1[m-1]==str2[n-1]) res=solve(str1,str2,dp,m-1,n-1);
	//     else res=1+min(solve(str1,str2,dp,m-1,n),solve(str1,str2,dp,m,n-1));
	//     return dp[m][n]=res;
	// }	
	
	int minOperations(string str1, string str2){
	    // Method-1: bottom-up
	    int m=str1.length(), n=str2.length();
	    vector<int> dp(n+1);
	    for(int j=0;j<=n;j++) dp[j]=j;
	    for(int i=1;i<=m;i++){
	        int prev2=0, prev=dp[0];
	        dp[0]=i;
	        for(int j=1;j<=n;j++){
	            prev2=prev;
	            prev=dp[j];
	            if(str1[i-1]==str2[j-1]) dp[j]=prev2;
	            else dp[j]=1+min(dp[j],dp[j-1]);
	        }
	    }
	    return dp[n];
	    
	    // Method-2: top-down
	    // int m=str1.length(), n=str2.length();
	    // vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
	    // return solve(str1,str2,dp,m,n);
	} 