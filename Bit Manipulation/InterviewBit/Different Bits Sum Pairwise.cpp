//problem link: https://www.interviewbit.com/problems/different-bits-sum-pairwise/

int Solution::cntBits(vector<int> &A) {
    //Sum of pairwise Hamming Distance
    long long res=0, mod=1e9+7;
    for(int i=0;i<32;i++){
        long long ones=0, zeros=0;
        for(int x:A){
            if(x&(1<<i)) ones++;
            else zeros++;
        }
        res=(res+2*zeros*ones)%mod;
    }
    return res;
}

