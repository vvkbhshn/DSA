//problem link: https://www.interviewbit.com/problems/perfect-peak-of-array/

int Solution::perfectPeak(vector<int> &A) {
    int n=A.size();
    int rMin[n];
    rMin[n-1]=A[n-1];
    for(int i=n-2;i>=0;i--){
        rMin[i]=min(A[i],rMin[i+1]);
    }
    int lMax=A[0];
    for(int i=1;i<n-1;i++){
        if(A[i]>lMax && A[i]<rMin[i+1]) return 1;
        lMax=max(lMax,A[i]);
    }
    return 0;
}
