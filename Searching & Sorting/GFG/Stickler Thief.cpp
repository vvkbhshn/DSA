//problem link: https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1

class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<vector<int>> dp(n,vector<int>(2));
        dp[0][0]=0;
        dp[0][1]=arr[0];
        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=arr[i]+dp[i-1][0];
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};