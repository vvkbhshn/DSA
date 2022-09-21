//problem link: https://www.interviewbit.com/problems/maximum-consecutive-gap/

int Solution::maximumGap(const vector<int> &A) {
    int n=A.size();
    if(n<=1) return 0;
    int maxi=*max_element(A.begin(),A.end());
    int mini=*min_element(A.begin(),A.end());
    double gap=(double)(maxi-mini)/(n-1);
    if(gap<1.0) gap=1;
    vector<pair<int,int>> bucket(n,{INT_MAX,INT_MIN});
    for(int i=0;i<n;i++){
        int index=(A[i]-mini)/gap;
        bucket[index].first=min(bucket[index].first,A[i]);
        bucket[index].second=max(bucket[index].second,A[i]);
    }
    int prev=bucket[0].second, res=0;
    for(int i=0;i<n;i++){
        if(bucket[i].first==INT_MAX) continue;
        res=max(res,bucket[i].first-prev);
        prev=bucket[i].second;
    }
    return res;
}
