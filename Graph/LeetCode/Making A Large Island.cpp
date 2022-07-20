//problem link: https://leetcode.com/problems/making-a-large-island/

class Solution {
public:
    
    void dfs(int i, int j, int n, int &color, int &currSize, vector<vector<int>> &grid){
        if(min(i,j)<0 || max(i,j)>=n || grid[i][j]!=1) return;
        grid[i][j]=color;
        currSize++;
        dfs(i-1,j,n,color,currSize,grid);
        dfs(i+1,j,n,color,currSize,grid);
        dfs(i,j-1,n,color,currSize,grid);
        dfs(i,j+1,n,color,currSize,grid);
    }
    
    
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size(), res=1;
        unordered_map<int,int> islandSize;
        int color=2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){                
                if(grid[i][j]==1){
                    int currSize=0;
                    dfs(i,j,n,color,currSize,grid);                   
                    islandSize[color]=currSize;
                    color++;
                    res=max(res,currSize);
                }                
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    set<int> values;
                    if(i>0 && grid[i-1][j]>1) values.insert(grid[i-1][j]);
                    if(j>0 && grid[i][j-1]>1) values.insert(grid[i][j-1]);
                    if(i<n-1 && grid[i+1][j]>1) values.insert(grid[i+1][j]);
                    if(j<n-1 && grid[i][j+1]>1) values.insert(grid[i][j+1]);
                    if(!values.empty()){
                        int temp=0;
                        for(auto x:values) temp+=islandSize[x];
                        res=max(res,1+temp);
                    }
                }
            }
        }
        return res;        
    }
};