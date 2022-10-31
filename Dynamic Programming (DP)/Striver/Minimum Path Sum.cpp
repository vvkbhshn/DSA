//problem link: https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<int> dp(n,INT_MAX);
        dp[0]=0;
        for(int i=0;i<m;i++){
            dp[0]+=grid[i][0];
            for(int j=1;j<n;j++){
                dp[j]=grid[i][j]+min(dp[j],dp[j-1]);
            }
        }
        return dp[n-1];
    }
};