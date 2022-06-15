//problem link: https://www.interviewbit.com/problems/number-of-1-bits/

int Solution::numSetBits(unsigned int n) {
    int cnt=0;
    
    // Method-1:
    return __builtin_popcount(n);
    
    // Method-2:
    // while(n){
    //     n=n&(n-1); //unsets the last set bit
    //     cnt++;
    // }
    
    // Method-3:
    // while(n){
    //     if(n&1) cnt++;
    //     n>>=1;
    // }
    
    return cnt;
}
