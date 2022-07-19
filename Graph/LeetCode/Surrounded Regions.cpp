//problem link: https://leetcode.com/problems/surrounded-regions/

class Solution {
public:
    int dir[5]={1,0,-1,0,1};
    
    void dfs(int i, int j, int m, int n, vector<vector<char>> &board){        
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]!='O') return;
        board[i][j]='#';
        for(int k=0;k<4;k++){
            dfs(i+dir[k],j+dir[k+1],m,n,board);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size();
        //DFS on first and last columns
        for(int i=0;i<m;i++){
            if(board[i][0]=='O') dfs(i,0,m,n,board);
            if(board[i][n-1]=='O') dfs(i,n-1,m,n,board);
        }
        //DFS on first and last rows
        for(int i=0;i<n;i++){
            if(board[0][i]=='O') dfs(0,i,m,n,board);
            if(board[m-1][i]=='O') dfs(m-1,i,m,n,board);
        }        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='#') board[i][j]='O';
            }
        }
    }
};