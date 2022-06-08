//problem link: https://www.interviewbit.com/problems/grid-unique-paths/

int Solution::uniquePaths(int A, int B) {
    // calculate C(A+B-2,A-1)
    long long res=1;
    for(int i=1;i<=B-1;i++){
        res=(res*(A+i-1))/i;
    }
    return res;
}
