//problem link: https://leetcode.com/problems/surrounded-regions/

class Solution {
public:    
    void dfs(vector<vector<char>>& board, int i, int j, int m, int n){
        if(i<0 || i>=m || j<0 || j>=n || board[i][j]!='O') return;
        board[i][j]='Y';
        dfs(board,i+1,j,m,n);
        dfs(board,i-1,j,m,n);
        dfs(board,i,j+1,m,n);
        dfs(board,i,j-1,m,n);
    }
    
    void solve(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size();
        for(int i=0;i<m;i++){
            dfs(board,i,0,m,n);
            dfs(board,i,n-1,m,n);
        }
        for(int j=0;j<n;j++){
            dfs(board,0,j,m,n);
            dfs(board,m-1,j,m,n);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='Y') board[i][j]='O';
            }
        }
    }
};