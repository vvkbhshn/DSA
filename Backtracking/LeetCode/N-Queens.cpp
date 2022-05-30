//problem link: https://leetcode.com/problems/n-queens/

class Solution {
public:    
    bool isValid(vector<string> &board, int x, int y){
        int n=board.size();
        for(int i=0;i<n;i++) if(board[i][y]=='Q') return false;
        for(int i=x, j=y; i>=0 && j>=0; i--, j--) if(board[i][j]=='Q') return false;
        for(int i=x, j=y; i>=0 && j<n; i--, j++) if(board[i][j]=='Q') return false;        
        return true;
    }
    
    void solvePuzzle(vector<vector<string>> &res, vector<string> &board, int row){
        int n=board.size();
        if(row==n){
            res.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(isValid(board,row,i)){
                board[row][i]='Q';
                solvePuzzle(res,board,row+1);
                board[row][i]='.';
            }
        }
    }    
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n,string(n,'.'));
        solvePuzzle(res,board,0);        
        return res;
    }
};