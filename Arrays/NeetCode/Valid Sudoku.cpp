//problem link: https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9]={false};
        bool col[9][9]={false};
        bool region[9][9]={false};
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                int idx=board[i][j]-'1';
                int area=(i/3)*3+(j/3);
                if(row[i][idx] || col[j][idx] || region[area][idx]) return false;
                row[i][idx]=true;
                col[j][idx]=true;
                region[area][idx]=true;
            }
        }        
        return true;
    }
};