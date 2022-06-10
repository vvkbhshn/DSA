//problem link: https://www.interviewbit.com/problems/woodcutting-made-easy/

int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    int l=0, r=*max_element(A.begin(),A.end()), mid;
    int res=0;
    while(l<=r){
        mid=l+(r-l)/2;
        long long cnt=0;
        for(auto x:A) if(x>mid) cnt+=(x-mid);
        if(cnt>=B){
            res=max(res,mid);
            l=mid+1;
        }
        else r=mid-1;
    }
    return res;
}
