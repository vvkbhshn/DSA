//problem link: https://www.interviewbit.com/problems/sudoku/

bool isValid(vector<vector<char>> &A, int x, int y, char c){
    for(int i=0;i<9;i++) if(A[x][i]==c || A[i][y]==c) return false;
    x=3*(x/3);
    y=3*(y/3);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(A[x+i][y+j]==c) return false;
        }
    }
    return true;
}

bool backtrack(vector<vector<char>> &A){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(A[i][j]=='.'){
                for(char c='1';c<='9';c++){
                    if(isValid(A,i,j,c)){
                        A[i][j]=c;
                        if(backtrack(A)) return true;
                        else A[i][j]='.';
                    }
                }
				return false;
            }
        }
    }    
    return true;
}

void Solution::solveSudoku(vector<vector<char>> &A) {
    backtrack(A);
}