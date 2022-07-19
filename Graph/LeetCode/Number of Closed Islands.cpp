//problem link: https://leetcode.com/problems/number-of-closed-islands/

class Solution {
private:
    int dir[5]={1,0,-1,0,1};
public:        
    bool dfs(int x, int y, int m, int n, vector<vector<int>> &grid){
        if(x<0 || x>=m || y<0 || y>=n) return false;
        if(grid[x][y]==1) return true;
        grid[x][y]=1;
        bool res=true;
        for(int i=0;i<4;i++){
            res=res & dfs(x+dir[i],y+dir[i+1],m,n,grid);
        }
        return res;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size() ,n=grid[0].size();
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0 && dfs(i,j,m,n,grid)) res++;
            }
        }
        return res;
    }
};