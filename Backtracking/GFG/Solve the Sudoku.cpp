//problem link: https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1

class Solution 
{
    public:    
    bool isValid(int grid[][N], int x, int y, int k){
        for(int i=0;i<N;i++){
            if(grid[i][y]==k || grid[x][i]==k) return false;
        }
        x=x-x%3;
        y=y-y%3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[x+i][y+j]==k) return false;
            }
        }
        return true;
    }
     
    bool SolveSudoku(int grid[N][N])  
    { 
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j]==0){
                    for(int k=1;k<=9;k++){
                        if(isValid(grid,i,j,k)){
                            grid[i][j]=k;
                            if(SolveSudoku(grid)) return true;
                            else grid[i][j]=0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void printGrid (int grid[N][N]) 
    {
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};