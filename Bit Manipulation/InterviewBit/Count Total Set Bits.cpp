//problem link: https://www.interviewbit.com/problems/count-total-set-bits/

int Solution::solve(int A) {
    if(A<2) return A;
    int p=log2(A), mod=1e9+7;
    long long res=0, num;
    for(int i=1;i<=p;i++){
        num=(1<<i)-(1<<(i-1));
        res=(2*res+num)%mod;
    }
    num=A-(1<<p)+1;
    res=(res+num+solve(num-1))%mod;
    return res;
}