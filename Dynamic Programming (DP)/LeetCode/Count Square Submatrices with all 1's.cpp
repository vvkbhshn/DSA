//problem link: https://leetcode.com/problems/count-square-submatrices-with-all-ones/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){                  
                // dp[i][j] means the size of biggest square with A[i][j] as bottom-right corner.
                // dp[i][j] also means the number of squares with A[i][j] as bottom-right corner.

                // If A[i][j] == 0, no possible square.
                // If A[i][j] == 1,
                // we compare the size of square dp[i-1][j-1], dp[i-1][j] and dp[i][j-1].
                // min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1 is the maximum size of square that we can find.

                // DP solution: [O(m*n) time, O(1) space]
                if(i>0 && j>0 && matrix[i][j]>0){
                    matrix[i][j]=1+min(matrix[i-1][j-1],
                                       min(matrix[i][j-1],matrix[i-1][j]));               
                }
                res+=matrix[i][j];
            }
        }
        return res;
    }
};