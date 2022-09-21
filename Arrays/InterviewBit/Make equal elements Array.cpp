//problem link: https://www.interviewbit.com/problems/make-equal-elements-array/

int Solution::solve(vector<int> &A, int B) {
    for(auto num:A){
        if(num%B!=0) return 0;
    }
    return 1;
}
