//problem link: https://www.interviewbit.com/problems/sum-of-pairwise-hamming-distance/

int Solution::hammingDistance(const vector<int> &A) {
    long long res=0, MOD=1000000007;
    for(int i=0;i<32;i++){
        long long bit0=0, bit1=0;
        for(auto x:A){
            if((1<<i) & x) bit1++;
            else bit0++;
        }
        res=(res+(2*bit0*bit1)%MOD)%MOD;
    }
    return res;
}
