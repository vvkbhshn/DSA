//problem link: https://leetcode.com/problems/cherry-pickup-ii/

class Solution {
public:
    // int solve(vector<vector<int>>& grid, vector<vector<vector<int>>> &dp, int m, int n, int row, int x, int y){
    //     if(row==m-1) return 0;
    //     if(dp[row][x][y]!=-1) return dp[row][x][y];
    //     if(dp[row][y][x]!=-1) return dp[row][x][y]=dp[row][y][x];
    //     int res=0;
    //     for(int i=-1;i<=1;i++){
    //         for(int j=-1;j<=1;j++){
    //             if(min(x+i,y+j)<0 || max(x+i,y+j)>=n) continue;
    //             if(x+i==y+j) res=max(res,grid[row+1][x+i]+solve(grid,dp,m,n,row+1,x+i,y+j));
    //             else res=max(res,grid[row+1][x+i]+grid[row+1][y+j]+solve(grid,dp,m,n,row+1,x+i,y+j));
    //         }
    //     }
    //     return dp[row][x][y]=res;
    // }    
    
    int cherryPickup(vector<vector<int>>& grid) {             
        // Method-1: bottom-up [O(m*n*n) time, O(n*n) space]
        int m=grid.size(), n=grid[0].size();
        vector<vector<vector<int>>> dp(2,vector<vector<int>>(n,vector<int>(n,0)));
        int index=1;
        for(int row=0;row<m;row++){
            for(int x=0;x<min(n,row+1);x++){
                for(int y=max(0,n-1-row);y<n;y++){
                    int res=0;
                    for(int i=-1;i<=1;i++){
                        for(int j=-1;j<=1;j++){
                            if(min(x+i,y+j)<0 || max(x+i,y+j)>=n) continue;
                            res=max(res,dp[1-index][x+i][y+j]);
                        }
                    }
                    if(x==y) dp[index][x][y]=grid[row][x]+res;
                    else dp[index][x][y]=grid[row][x]+grid[row][y]+res;
                }
            }
            index=1-index;
        }
        index=1-index;
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                res=max(res,dp[index][i][j]);
            }
        }
        return res;
        
        // Method-2: top-down [O(m*n*n) time, O(m*n*n) space]
        // int m=grid.size(), n=grid[0].size();        
        // vector<vector<vector<int>>> dp(m,vector<vector<int>> (n,vector<int>(n,-1)));
        // return grid[0][0]+grid[0][n-1]+solve(grid,dp,m,n,0,0,n-1);
    }
};