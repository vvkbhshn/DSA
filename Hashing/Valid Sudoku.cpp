//problem link: https://www.interviewbit.com/problems/valid-sudoku/

int Solution::isValidSudoku(const vector<string> &A) {
    vector<unordered_set<char>> row(9), col(9), box(9);    
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(A[i][j]=='.') continue;
            int idx=3*(i/3)+(j/3);
            if(row[i].find(A[i][j])!=row[i].end()) return 0;
            if(col[j].find(A[i][j])!=col[j].end()) return 0;
            if(box[idx].find(A[i][j])!=box[idx].end()) return 0;
            row[i].insert(A[i][j]);
            col[j].insert(A[i][j]);
            box[idx].insert(A[i][j]);
        }
    }
    return 1;
}