//problem link: https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1

class Solution{
public:

    bool isValid(vector<vector<int>> &grid, int &n, int row, int col){
        for(int i=row, j=col-1; j>=0; j--) if(grid[i][j]==1) return false;
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) if(grid[i][j]==1) return false;
        for(int i=row+1, j=col-1; i<n && j>=0; i++, j--) if(grid[i][j]==1) return false;
        return true;
    }

    void backtrack(vector<vector<int>> &grid, vector<vector<int>> &res,
                    int &n, vector<int> &curr, int col){
        
        if(col==n){
            res.push_back(curr);
            return;
        }
        for(int i=0;i<n;i++){
            if(isValid(grid,n,i,col)){
                grid[i][col]=1;
                curr[col]=i+1;
                backtrack(grid,res,n,curr,col+1);
                curr[col]=0;
                grid[i][col]=0;
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> res;
        vector<vector<int>> grid(n,vector<int>(n,0));
        vector<int> curr(n,0);
        backtrack(grid,res,n,curr,0);
        return res;
    }
};