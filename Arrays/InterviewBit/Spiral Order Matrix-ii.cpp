//problem link: https://www.interviewbit.com/problems/spiral-order-matrix-ii/

vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int>> v(A,vector<int>(A));
    int left=0, right=A-1, top=0, bottom=A-1;
    int count=1;
    while(count<=A*A){
        for(int i=left;i<=right && count<=A*A;i++){
            v[top][i]=count;
            count++;
        }
        top++;
        for(int i=top;i<=bottom && count<=A*A;i++){
            v[i][right]=count;
            count++;
        }
        right--;
        for(int i=right;i>=left && count<=A*A;i--){
            v[bottom][i]=count;
            count++;
        }
        bottom--;
        for(int i=bottom;i>=top && count<=A*A;i--){
            v[i][left]=count;
            count++;
        }
        left++;
    }
    return v;
}
