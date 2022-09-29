//problem link: https://www.interviewbit.com/problems/sorted-permutation-rank/

int MOD=1000003;

int Solution::findRank(string A) {
    int n=A.length();
    int freq[256]={0};
    long long res=0, fact=1;
    for(int i=n-1;i>=0;i--){
        long long cnt=0;
        for(int j=0;j<(int)A[i];j++){
            cnt=(cnt+freq[j])%MOD;
        }
        res=(res+cnt*fact)%MOD;
        fact=(fact*(n-i))%MOD;
        freq[A[i]]++;
    }
    return (res+1)%MOD;
}
