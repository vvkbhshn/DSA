//problem link: https://www.interviewbit.com/problems/pick-from-both-sides/

int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    int temp=0;
    int sum[n];
    int res=INT_MAX;
    for(int i=0;i<n;i++){
        temp+=A[i];
        sum[i]=temp;
    }
    if(B==n) return sum[n-1];
    int minSubarray=sum[n-B-1];
    for(int i=n-B;i<n;i++){
        minSubarray=min(minSubarray,sum[i]-sum[i+B-n]);
    }
    return sum[n-1]-minSubarray;
}
