//problem link: https://leetcode.com/problems/rotting-oranges/

class Solution {
private:
    int dir[5]={1,0,-1,0,1};
public:
    bool isValid(vector<vector<int>>& grid, int i, int j, int m, int n){
        return i>=0 && i<m && j>=0 && j<n && grid[i][j]==1;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int minutes=0, fresh=0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) fresh++;
                else if(grid[i][j]==2) q.push({i,j});
            }
        }
        if(fresh==0) return 0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto p=q.front();
                q.pop();
                int x=p.first, y=p.second;
                for(int i=0;i<4;i++){
                    int newX=x+dir[i], newY=y+dir[i+1];
                    if(isValid(grid,newX,newY,m,n)){
                        grid[newX][newY]=2;
                        q.push({newX,newY});
                        fresh--;
                    }
                }
            }
            minutes++;
        }
        if(fresh>0) return -1;
        return minutes-1;
    }
};