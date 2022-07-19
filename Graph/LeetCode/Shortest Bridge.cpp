//problem link: https://leetcode.com/problems/shortest-bridge/

class Solution {
public:
    int dir[5]={1,0,-1,0,1};
    
    void dfs(int i, int j, int n, vector<vector<int>>& grid, queue<pair<int,int>> &q){
        if(min(i,j)<0 || max(i,j)>=n || grid[i][j]!=1) return;
        grid[i][j]=2;
        q.push({i,j});
        for(int k=0;k<4;k++) dfs(i+dir[k],j+dir[k+1],n,grid,q);
    }
    
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> q;
        bool flag=false;
        for(int i=0;i<n;i++){            
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    //change the values of one island to 2 using DFS so that,
                    //one island will have values of 1 and the other one have values of 2.
                    dfs(i,j,n,grid,q);
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        //find the shortest distance b/w group of 1's and 2's using BFS
        int count=0;        
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto p=q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int x=p.first+dir[k], y=p.second+dir[k+1];                    
                    if(min(x,y)>=0 && max(x,y)<n && grid[x][y]!=2){
                        if(grid[x][y]==1) return count;
                        grid[x][y]=2;
                        q.push({x,y});
                    }
                }
            }
            count++;
        }
        return -1;        
    }
};