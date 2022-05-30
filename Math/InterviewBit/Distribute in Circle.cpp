//problem link: https://www.interviewbit.com/problems/distribute-in-circle/

int Solution::solve(int A, int B, int C) {
    return (A+C-1)%B;
}
