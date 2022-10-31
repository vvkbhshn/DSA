//problem link: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size(), n=grid[0].size();
        int moves=0;
        vector<vector<int>> vis(m,vector<int>(n,-1));
        queue<array<int,3>> q;
        q.push({0,0,k});
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto p=q.front();
                q.pop();
                int x=p[0], y=p[1], currK=p[2];
                if(x<0 || x>=m || y<0 || y>=n) continue;
                if(x==m-1 && y==n-1) return moves;
                if(grid[x][y]==1){
                    if(currK>0) currK--;
                    else continue;
                }
                if(vis[x][y]!=-1 && vis[x][y]>=currK) continue;
                vis[x][y]=currK;
                q.push({x+1,y,currK});
                q.push({x-1,y,currK});
                q.push({x,y+1,currK});
                q.push({x,y-1,currK});
            }
            moves++;
        }
        return -1;
    }
};