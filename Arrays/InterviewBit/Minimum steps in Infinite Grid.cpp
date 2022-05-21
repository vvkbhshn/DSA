// problem link: https://www.interviewbit.com/problems/min-steps-in-infinite-grid/

int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int n=A.size(), res=0;
    for(int i=1;i<n;i++){
        int delX=abs(A[i]-A[i-1]);
        int delY=abs(B[i]-B[i-1]);
        if(delY>=delX) res+=delY;
        else res+=delX;
    }
    return res;
}