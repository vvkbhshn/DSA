//problem link: https://leetcode.com/problems/sudoku-solver/

class Solution {
public:    
    bool isValid(vector<vector<char>>& board, int x, int y, char c){
        for(int i=0;i<9;i++) if(board[x][i]==c || board[i][y]==c) return false;
        x=x-x%3;
        y=y-y%3;
        for(int i=0;i<3;i++) for(int j=0;j<3;j++) if(board[x+i][y+j]==c) return false;
        return true;           
    }
    
    bool solve(vector<vector<char>> &board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isValid(board,i,j,c)){
                            board[i][j]=c;
                            if(solve(board)) return true;
                            else board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;                 
    }
    
    void solveSudoku(vector<vector<char>>& board) {    
        solve(board);        
    }
};