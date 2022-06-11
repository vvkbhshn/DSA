//problem link: https://www.interviewbit.com/problems/implement-power-function/

int Solution::pow(int x, int n, int d) {
    if(x==0) return 0;
    long long X=x;
    long long res=1;
    while(n){
        if(n&1) res=(res*X)%d;
        X=(X*X)%d;
        n>>=1;
    }
    return res<0? res+d: res;
}
