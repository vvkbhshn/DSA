//problem link: https://www.interviewbit.com/problems/matrix-median/

int Solution::findMedian(vector<vector<int> > &A) {
    int n=A.size(), m=A[0].size();
    int l=A[0][0], r=A[0][m-1], mid, res;
    for(auto x:A){
        l=min(l,x[0]);
        r=max(r,x[m-1]);
    }    
    while(l<=r){
        mid=l+(r-l)/2;
        int cnt=0;
        for(int i=0;i<n;i++) cnt+=upper_bound(A[i].begin(),A[i].end(),mid)-A[i].begin();
        if(cnt<(n*m+1)/2) l=mid+1;
        else{
            res=mid;
            r=mid-1;
        }       
    }    
    return res;
}
