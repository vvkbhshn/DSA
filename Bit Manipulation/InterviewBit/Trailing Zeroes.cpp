//problem link: https://www.interviewbit.com/problems/trailing-zeroes/

int Solution::solve(int A) {
    int cnt=0;
    while((A&1)==0){
        A>>=1;
        cnt++;
    }
    return cnt;
}
