//problem link: https://www.interviewbit.com/problems/set-matrix-zeros/

void Solution::setZeroes(vector<vector<int> > &A) {
    int m=A.size(), n=A[0].size();
    int row0=1, col0=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(A[i][j]==0){
                if(i==0) row0=0;
                if(j==0) col0=0;
                A[i][0]=0;
                A[0][j]=0;
            }
        }
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(A[i][0]==0 || A[0][j]==0) A[i][j]=0;
        }
    }
    if(row0==0) for(int j=0;j<n;j++) A[0][j]=0;
    if(col0==0) for(int i=0;i<m;i++) A[i][0]=0;
}
