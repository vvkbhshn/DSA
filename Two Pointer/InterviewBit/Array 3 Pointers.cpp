//problem link: https://www.interviewbit.com/problems/array-3-pointers/

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int sizeOfA=A.size(), sizeOfB=B.size(), sizeOfC=C.size();
    int i=0, j=0, k=0;
    int res=INT_MAX;
    while(i<sizeOfA && j<sizeOfB && k<sizeOfC){
        int val=max((max(abs(A[i]-B[j]),abs(B[j]-C[k]))),abs(C[k]-A[i]));
        res=min(res,val);
        if(A[i]<=B[j] && A[i]<=C[k]) i++;
        else if(B[j]<=A[i] && B[j]<=C[k]) j++;
        else k++;
    }
    return res;
}
