//problem link: https://www.interviewbit.com/problems/nqueens/

bool isValid(vector<string> &curr, int n, int x, int y){
    for(int i=0;i<x;i++) if(curr[i][y]=='Q') return false;
    for(int i=x-1,j=y-1; i>=0 && j>=0; i--,j--) if(curr[i][j]=='Q') return false;
    for(int i=x-1,j=y+1; i>=0 && j<n; i--,j++) if(curr[i][j]=='Q') return false;
    return true;
}

void backtrack(int n, vector<vector<string>> &res, vector<string> &curr, int row){
    if(row==n){
        res.push_back(curr);
        return;
    }
    for(int i=0;i<n;i++){
        if(isValid(curr,n,row,i)){
            curr[row][i]='Q';
            backtrack(n,res,curr,row+1);
            curr[row][i]='.';
        }
    }
}

vector<vector<string>> Solution::solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> curr(n,string(n,'.'));
    backtrack(n,res,curr,0);
    return res;
}