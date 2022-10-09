//problem link: https://www.interviewbit.com/problems/container-with-most-water/

int Solution::maxArea(vector<int> &A) {
    int n=A.size(), res=0;
    int i=0, j=n-1;
    while(i<j){
        res=max(res,min(A[i],A[j])*(j-i));
        if(A[i]<A[j]) i++;
        else j--;
    }
    return res;
}