//problem link: https://www.interviewbit.com/problems/pick-from-both-sides/

int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    int sum=0, temp=0;
    for(int i=0;i<n-B;i++){
        sum+=A[i];
        temp+=A[i];
    }
    int minSubarraySum=temp;
    for(int i=n-B;i<n;i++){
        //Sliding Window Technique to calculate sum of subarrays of length n-B
        temp=temp+A[i]-A[i-(n-B)];
        minSubarraySum=min(minSubarraySum,temp);
        sum+=A[i];
    }
    return sum-minSubarraySum;
}