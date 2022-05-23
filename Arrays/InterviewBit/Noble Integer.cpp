//problem link: https://www.interviewbit.com/problems/noble-integer/

int Solution::solve(vector<int> &A) {
    int n=A.size();
    sort(A.rbegin(),A.rend());
    if(A[0]==0) return 1;
    for(int i=1;i<n;i++){
        if(A[i-1]!=A[i] && A[i]==i) return 1;
    }
    return -1;
}
