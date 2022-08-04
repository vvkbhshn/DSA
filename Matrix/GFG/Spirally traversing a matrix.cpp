//problem link: https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1

class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> res;
        int left=0, right=c-1, top=0, down=r-1, count=r*c;
        while(count>0){
            for(int j=left; j<=right && count>0; j++){
                res.push_back(matrix[top][j]);
                count--;
            }
            top++;
            for(int i=top; i<=down && count>0; i++){
                res.push_back(matrix[i][right]);
                count--;
            }
            right--;
            for(int j=right; j>=left && count>0; j--){
                res.push_back(matrix[down][j]);
                count--;
            }
            down--;
            for(int i=down; i>=top && count>0; i--){
                res.push_back(matrix[i][left]);
                count--;
            }
            left++;
        }
        return res;
    }
};