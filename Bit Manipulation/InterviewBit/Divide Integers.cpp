//problem link: https://www.interviewbit.com/problems/divide-integers/

int Solution::divide(int A, int B) {
    long long a=labs(A), b=labs(B), res=0;
    int sign= (A>0)^(B>0) ? -1: 1;
    while(a>=b){
        int n=0;
        while((b<<n)<=a) ++n;
        --n;
        res+=1LL<<n;
        a-=(b<<n);
    }
    return (sign*res<INT_MIN || sign*res>INT_MAX)? INT_MAX: sign*res;
}
