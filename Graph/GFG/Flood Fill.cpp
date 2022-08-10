//problem link: https://leetcode.com/problems/flood-fill/

class Solution {
public:
    int dir[5]={1,0,-1,0,1};
    
    void dfs(int x, int y, vector<vector<int>>& image, int &flag, int &color){
        int m=image.size(), n=image[0].size();
        if(x<0 || y<0 || x>=m || y>=n || image[x][y]==color || image[x][y]!=flag) return;
        image[x][y]=color;
        for(int i=0;i<4;i++) dfs(x+dir[i],y+dir[i+1],image,flag,color);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int flag=image[sr][sc];
        dfs(sr,sc,image,flag,color);
        return image;
    }
};