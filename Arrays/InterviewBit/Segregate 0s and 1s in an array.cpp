//problem link: https://www.interviewbit.com/problems/segregate-0s-and-1s-in-an-array/

vector<int> Solution::solve(vector<int> &A) {
    int n=A.size(), idx=0;
    for(int i=0;i<n;i++){
        if(A[i]==0) swap(A[i],A[idx++]);
    }
    return A;
}
