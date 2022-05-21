//problem link: https://leetcode.com/problems/max-area-of-island/

class Solution {
public:
    
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return 0;
        if(vis[i][j] || grid[i][j]==0) return 0;
        vis[i][j]=true;
        int cnt=1;
        cnt+=dfs(grid,vis,i+1,j);
        cnt+=dfs(grid,vis,i-1,j);
        cnt+=dfs(grid,vis,i,j+1);
        cnt+=dfs(grid,vis,i,j-1); 
        return cnt;
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]) res=max(res,dfs(grid,vis,i,j));
            }
        }
        return res;
    }
};