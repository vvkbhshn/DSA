//Problem link: https://www.interviewbit.com/problems/repeat-and-missing-number-array/

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    //Method-1: constant space
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

    //Method-2: requires O(n) space
    // int n=A.size(), p=n+1;
    // int temp[n]={0};
    // for(int i=0;i<n;i++) temp[A[i]-1]++;
    // int a,b;
    // for(int i=0;i<n;i++){
    //     if(temp[i]==2) a=i+1;
    //     else if(temp[i]==0) b=i+1;
    // }
    // return {a,b};
}
