//problem link: https://www.interviewbit.com/problems/sorted-permutation-rank/

int MOD=1000003;
int Solution::findRank(string A) {
    int n=A.length();
    long long fact[n+1], temp=1;
    for(int i=1;i<=n;i++){
        temp=(temp*i)%MOD;
        fact[i]=temp;
    }
    long long res=1;
    long long freq[256]={0};
    for(int i=0;i<n;i++) freq[(int)A[i]]++;
    for(int i=0;i<n;i++){
        long long cnt=0;
        for(int j=0;j<(int)A[i];j++){
            if(freq[j]>0) cnt+=freq[j];
        }
        res=(res+(cnt*fact[n-1-i])%MOD)%MOD;
        freq[(int)A[i]]--;
    }
    return res;
}
