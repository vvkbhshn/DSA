//Problem link: https://www.interviewbit.com/problems/repeat-and-missing-number-array/

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long n=A.size();
    long long sumDiff=(n*(n+1))/2;
    long long squareSumDiff=(n*(n+1)*(2*n+1))/6;
    for(int i=0;i<n;i++){
        sumDiff-=(long long)A[i];
        squareSumDiff-=(long long)A[i]*(long long)A[i];
    }
    int missing=(sumDiff+squareSumDiff/sumDiff)/2;
    int duplicate=missing-sumDiff;
    return {duplicate,missing};
}