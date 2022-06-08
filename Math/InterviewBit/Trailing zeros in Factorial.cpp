//problem link: https://www.interviewbit.com/problems/trailing-zeros-in-factorial/

int Solution::trailingZeroes(int A) {
    // the no. of trailing zeros depend on the power of 10 i.e. the power of 2x5
    // since the power of 5 will always be less than the power of 2 
    // so, the power of 5 will eventually decide the no. of zeros (power of 10) 
    int res=0;
    for(int p=5;p<=A;p*=5) res+=A/p;
    return res;
}
