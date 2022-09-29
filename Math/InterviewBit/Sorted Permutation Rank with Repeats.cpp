//problem link: https://www.interviewbit.com/problems/sorted-permutation-rank-with-repeats/

long long MOD=1e6+3;

long long binpow(long long a, long long n){
    if(a==1) return 1;
    long long res=1;
    while(n>0){
        if(n&1) res=(res*a)%MOD;
        a=(a*a)%MOD;
        n>>=1;
    }
    return res;
}

int Solution::findRank(string A) {
    int n=A.length();
    long long freq[256]={0};
    long long fact[n];
    for(auto c:A) freq[c]++;
    fact[0]=1;
    for(long long i=1;i<n;i++){
        fact[i]=((i%MOD)*(fact[i-1]%MOD))%MOD;
    }
    long long res=0;
    for(int i=0;i<n;i++){
        long long cnt=0, p=1;
        for(int j=0;j<256;j++){
            if(j<A[i]) cnt+=freq[j];
            p=(p*fact[freq[j]])%MOD;
        }
        //(1/x) = (x^(m-2))%m  -Fermat's little theorem
        p=binpow(p,MOD-2)%MOD;
        res=(res+((cnt*fact[n-1-i])%MOD*p)%MOD)%MOD;
        freq[A[i]]--;
    }
    return (res+1)%MOD;
}
