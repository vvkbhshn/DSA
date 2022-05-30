//problem link: https://www.interviewbit.com/problems/total-moves-for-bishop/

int Solution::solve(int A, int B) {
    return min(A-1,B-1)+min(A-1,8-B)+min(8-A,B-1)+min(8-A,8-B);
}
