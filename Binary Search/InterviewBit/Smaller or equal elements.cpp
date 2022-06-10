//problem link: https://www.interviewbit.com/problems/smaller-or-equal-elements/ 

int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    int l=0, r=n, mid;
    while(l<r){
        mid=l+(r-l)/2;
        if(A[mid]>B) r=mid;
        else l=mid+1;
    }
    return l;
}
