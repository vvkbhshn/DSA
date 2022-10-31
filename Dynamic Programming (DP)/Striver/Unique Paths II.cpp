//problem link: https://leetcode.com/problems/unique-paths-ii/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<int> dp(n);
        bool found=false;
        for(int i=0;i<n;i++){
            if(grid[0][i]==1) found=true;
            if(found) dp[i]=0;
            else dp[i]=1;
        }
        for(int i=1;i<m;i++){
            if(grid[i][0]==1) dp[0]=0;
            for(int j=1;j<n;j++){
                if(grid[i][j]==1) dp[j]=0;
                else dp[j]=dp[j]+dp[j-1];
            }
        }
        return dp[n-1];
    }
};