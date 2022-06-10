//problem link: https://www.interviewbit.com/problems/square-root-of-integer/

int Solution::sqrt(int A) {
    int l=0, r=A, res=0;
    while(l<=r){
        long long mid=l+(r-l)/2;
        if(mid*mid<=A){
            res=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return res;
}
