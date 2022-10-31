//problem link: https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1
    
int lootHouse(int n, int arr[], vector<int> &dp){
	//base cases
	if(n==0) return 0;
	if(n==1) return arr[0];
	if(dp[n]!=-1) return dp[n];
	return dp[n]=max(arr[n-1]+lootHouse(n-2,arr,dp),lootHouse(n-1,arr,dp));
}

//Function to find the maximum money the thief can get.
int FindMaxSum(int arr[], int n){
	vector<int> dp(n+1,-1);
	return lootHouse(n,arr,dp);
}