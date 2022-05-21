//problem link: https://www.interviewbit.com/problems/next-permutation/

int search(vector<int> &A, int l, int r, int num){
    int idx=-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(A[mid]<=num) r=mid-1;
        else{
            l=mid+1;
            if(idx==-1 || A[idx]>=A[mid]) idx=mid;
        }
    }
    return idx;
}

vector<int> Solution::nextPermutation(vector<int> &A) {
    int n=A.size();
    int i,j;
    for(i=n-2;i>=0;i--){
        if(A[i]<A[i+1]) break;
    }
    if(i==-1){
        reverse(A.begin(),A.end());
        return A;
    }
    // for(j=n-1;j>i;j--){
    //     //this can be further optimized by using binary search
    //     if(A[j]>A[i]) break;
    // }
    j=search(A,i+1,n-1,A[i]);
    swap(A[i],A[j]);
    reverse(A.begin()+i+1,A.end());
    return A;
}
