//problem link: https://www.interviewbit.com/problems/matrix-search/

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int m=A.size(), n=A[0].size();
    int l=0, r=m*n-1, mid;
    while(l<=r){
        mid=l+(r-l)/2;
        int x=mid/n, y=mid%n;
        if(A[x][y]<B) l=mid+1;
        else if(A[x][y]>B) r=mid-1;
        else return 1; 
    }
    return 0;
}

