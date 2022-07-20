//problem link: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

class Solution {
public:
    int dir[5]={1,0,-1,0,1};
    
    bool isValid(int i, int j, int m, int n){
        return i>=0 && j>=0 && i<m && j<n;
    }
        
    int dfs(int i, int j, int m, int n, vector<vector<int>> &dp, vector<vector<int>> &matrix){
        if(!isValid(i,j,m,n)) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int res=0;
        for(int k=0;k<4;k++){
            int newX=i+dir[k], newY=j+dir[k+1];
            if(isValid(newX,newY,m,n) && matrix[newX][newY]>matrix[i][j]){
               res=max(res,dfs(newX,newY,m,n,dp,matrix)); 
            } 
        }
        return dp[i][j]=1+res;
    }
    
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]==-1) res=max(res,dfs(i,j,m,n,dp,matrix));
            }
        }
        return res;
    }
};