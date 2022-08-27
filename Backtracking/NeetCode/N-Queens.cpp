//problem link: https://leetcode.com/problems/n-queens/

class Solution {
public:    
    bool isValid(vector<string> &curr, int x, int y, int n){
        for(int i=x-1;i>=0;i--) if(curr[i][y]=='Q') return false;
        for(int i=x-1,j=y-1; i>=0 && j>=0; i--,j--) if(curr[i][j]=='Q') return false;
        for(int i=x-1,j=y+1; i>=0 && j<n; i--,j++) if(curr[i][j]=='Q') return false;
        return true;
    }
    
    void solve(vector<vector<string>> &res, vector<string> &curr, int row, int n){
        if(row==n){
            res.push_back(curr);
            return;
        }
        for(int col=0;col<n;col++){
            curr[row][col]='Q';
            if(isValid(curr,row,col,n)){
                solve(res,curr,row+1,n);
            }
            curr[row][col]='.';
        }
    }    
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> curr(n,string(n,'.'));
        solve(res,curr,0,n);
        return res;
    }
};