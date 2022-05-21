//problem link: https://www.interviewbit.com/problems/max-min-05542f2f-69aa-4253-9cc7-84eb7bf739c4/

int Solution::solve(vector<int> &A) {
    int maxNum=INT_MIN, minNum=INT_MAX;
    for(auto x:A){
        maxNum=max(maxNum,x);
        minNum=min(minNum,x);
    }
    return maxNum+minNum;
}
