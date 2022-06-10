//problem link: https://www.interviewbit.com/problems/sorted-insert-position/

int Solution::searchInsert(vector<int> &A, int B) {
    int n=A.size(), res=n;
    int l=0, r=n-1, mid;
    if(B<A[0]) return 0;
    while(l<=r){
        mid=l+(r-l)/2;
        if(A[mid]<B){
            res=mid;
            l=mid+1;
        }
        else if(A[mid]>B) r=mid-1;
        else return mid;
    }
    return res+1;
}
