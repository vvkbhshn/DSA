//problem link: https://www.interviewbit.com/problems/find-duplicate-in-array/

int Solution::repeatedNumber(const vector<int> &A) {
    int n=A.size();
    int slow=A[0], fast=A[A[0]];
    while(slow!=fast){
        slow=A[slow];
        fast=A[A[fast]];
    }
    slow=0;
    while(slow!=fast){
        slow=A[slow];
        fast=A[fast];
    }
    return slow;
}
