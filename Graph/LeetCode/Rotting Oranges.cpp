//problem link: https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    bool  isValid(int x, int y, int m, int n){
        return x>=0 && x<m && y>=0 && y<n;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        queue<pair<int,int>> q;
        int fresh=0, time=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) fresh++;
                else if(grid[i][j]==2) q.push({i,j});
            }
        }
        if(fresh==0) return 0;
        int dir[]={1,0,-1,0,1};
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto p=q.front(); q.pop();
                int x=p.first, y=p.second;
                for(int i=0;i<4;i++){
                    int X=x+dir[i], Y=y+dir[i+1];
                    if(isValid(X,Y,m,n) && grid[X][Y]==1){
                        grid[X][Y]=2;
                        q.push({X,Y});
                        fresh--;
                    }
                }
            }
            time++;
        }
        if(fresh>0) return -1; 
        return time-1;
    }
};