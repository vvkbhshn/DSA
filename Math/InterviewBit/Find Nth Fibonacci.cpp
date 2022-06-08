//problem link: https://www.interviewbit.com/problems/find-nth-fibonacci/

int MOD=1e9+7;

void multiplyMatrix(long long A[][2], long long B[][2]){
    long long temp[2][2];
    temp[0][0]=(A[0][0]*B[0][0]+A[0][1]*B[1][0])%MOD;
    temp[0][1]=(A[0][0]*B[0][1]+A[0][1]*B[1][1])%MOD;
    temp[1][0]=(A[1][0]*B[0][0]+A[1][1]*B[1][0])%MOD;
    temp[1][1]=(A[1][0]*B[0][1]+A[1][1]*B[1][1])%MOD;
    for(int i=0;i<2;i++) for(int j=0;j<2;j++) A[i][j]=temp[i][j];
}

// pair<long long, long long> fib(int n){
//     // pair = {F(n), F(n+1)}
//     if(n==0) return {0,1};
//     pair<long long, long long> p=fib(n>>1);
//     long long a=p.first, b=p.second;

//     // F(2n) = F(n)*[2F(n+1)-F(n)]
//     long long c=2*b-a;
//     if(c<0) c+=MOD;
//     c= (c*a)%MOD;

//     // F(2n+1) = [F(n)]^2 + [F(n+1)]^2
//     long long d=(a*a+b*b)%MOD;

//     if(n&1) return {d,(c+d)%MOD};
//     else return {c,d}; 
// }


int Solution::solve(int A) {

    // Method-1: Matrix Exponentiation
    // [F(n) F(n+1)] = [F(0) F(1)]. P^n
    // P = [0 1]
    //     [1 1]
    long long F[2][2]={{1,0},{0,1}};
    long long P[2][2]={{0,1},{1,1}};
    int n=A;
    while(n){
        if(n&1) multiplyMatrix(F,P);
        multiplyMatrix(P,P);
        n>>=1;
    }
    return F[1][0];

    // Method-2: Fast Doubling
    // F(2n) = F(n)*[F(n+1)+F(n-1)]
    // eq. 1 => F(2n) = F(n)*[2F(n+1)-F(n)]
    // eq. 2 => F(2n+1) = [F(n)]^2 + [F(n+1)]^2
    // pair<long long,long long> F=fib(A);
    // return F.first;
}
