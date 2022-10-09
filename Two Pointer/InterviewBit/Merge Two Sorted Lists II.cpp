//problem link: https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/

void Solution::merge(vector<int> &A, vector<int> &B) {
    int n=A.size(), m=B.size();
    A.resize(n+m);
    int index=m+n-1;
    int i=n-1, j=m-1;
    while(i>=0 && j>=0){
        if(A[i]>B[j]) A[index--]=A[i--];
        else A[index--]=B[j--];
    } 
    while(i>=0) A[index--]=A[i--];
    while(j>=0) A[index--]=B[j--];
}
