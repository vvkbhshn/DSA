//problem link: https://leetcode.com/problems/as-far-from-land-as-possible/

class Solution {
public:    
    bool isValid(int x, int y, int n){
        return x>=0 && x<n && y>=0 && y<n;
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        bool vis[100][100]={false};
        int dir[]={1,0,-1,0,1};
        int count=-1;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(grid[i][j]==1) q.push({i,j});
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto p=q.front();
                q.pop();
                int x=p.first, y=p.second;
                for(int k=0;k<4;k++){
                    int xx=x+dir[k], yy=y+dir[k+1];
                    if(isValid(xx,yy,n) && grid[xx][yy]==0){
                        q.push({xx,yy});
                        grid[xx][yy]=1;
                    }
                }
            }
            count++;
        }
        return (count==0)? -1: count;
    }
};