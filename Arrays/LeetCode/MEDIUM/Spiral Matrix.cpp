//problem link: https://leetcode.com/problems/spiral-matrix/submissions/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector<int> res;
        int top=0, bottom=m-1, left=0, right=n-1;
        int count=0;
        while(count<m*n){
            for(int j=left; j<=right && count<m*n; j++){
                res.push_back(matrix[top][j]);
                count++;
            }
            top++;
            for(int i=top; i<=bottom && count<m*n; i++){
                res.push_back(matrix[i][right]);
                count++;
            }
            right--;
            for(int j=right; j>=left && count<m*n; j--){
                res.push_back(matrix[bottom][j]);
                count++;
            }
            bottom--;
            for(int i=bottom; i>=top && count<m*n; i--){
                res.push_back(matrix[i][left]);
                count++;
            }
            left++;
        }
        return res;
    }
};