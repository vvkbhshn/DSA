//problem link: https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        bool row0=false, col0=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    if(i==0) row0=true;
                    else if(j==0) col0=true;
                    else matrix[i][0]=matrix[0][j]=0;
                }
            }
        }
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==0 && row0==true) matrix[i][j]=0;
                else if(j==0 && col0==true) matrix[i][j]=0;
                else if(matrix[i][0]==0 || matrix[0][j]==0) matrix[i][j]=0;
            }
        }
        
        // 2nd method: take more space O(m+n)
        // int col[201]={0}, row[201]={0};
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(matrix[i][j]==0){
        //             row[i]=col[j]=1;
        //         }
        //     }
        // }
        // for(int i=0;i<m;i++){
        //     if(row[i]==1) for(int j=0;j<n;j++) matrix[i][j]=0;
        // }
        // for(int i=0;i<n;i++){
        //     if(col[i]==1) for(int j=0;j<m;j++) matrix[j][i]=0;
        // }
    }
};