//problem link: https://leetcode.com/problems/number-of-islands/

class Solution {
public:    
    void dfs(int x, int y, int m, int n, vector<vector<char>> &grid){        
        if(x<0 || x==m || y<0 || y==n || grid[x][y]=='0') return;
        //for marking grid[x][y] as visited, we change grid[x][y] to '0'
        grid[x][y]='0';
        dfs(x-1,y,m,n,grid);
        dfs(x+1,y,m,n,grid);
        dfs(x,y-1,m,n,grid);
        dfs(x,y+1,m,n,grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,m,n,grid);
                    count++;
                }
            }
        }
        return count;
    }
};