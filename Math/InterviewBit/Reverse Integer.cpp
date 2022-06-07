//problem link: https://www.interviewbit.com/problems/reverse-integer/

int Solution::reverse(int A) {
    int res=0;
    while(A){
        if(res>INT_MAX/10 || res<INT_MIN/10) return 0;
        res=res*10+A%10;
        A/=10;
    }
    return res;
}
