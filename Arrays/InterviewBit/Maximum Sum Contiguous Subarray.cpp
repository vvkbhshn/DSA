//problem link: https://www.interviewbit.com/problems/max-sum-contiguous-subarray/

int Solution::maxSubArray(const vector<int> &A) {
    int n=A.size();
    int res=A[0], curr=0;
    for(int i=0;i<n;i++){
        curr+=A[i];
        res=max(res,curr);
        if(curr<0) curr=0;
    }
    return res;
}
