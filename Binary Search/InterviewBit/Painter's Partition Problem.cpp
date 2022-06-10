//problem link: https://www.interviewbit.com/problems/painters-partition-problem/

int Solution::paint(int A, int B, vector<int> &C) {
    int n=C.size();
    long long l=0, r=0, mid;
    long long res=0;
    for(auto x:C){
        if(x>l) l=x;
        r+=x;
    }
    while(l<=r){
        // mid = total length of board to be painted by an individual painter
        mid=l+(r-l)/2;
        int cnt=1, curr=0;
        for(auto x:C){
            curr+=x;
            if(curr>mid){
                curr=x;
                cnt++;
            }
        }
        if(cnt>A) l=mid+1;
        else{
            res=mid;
            r=mid-1;
        }
    }
    return (res*B)%10000003;
}
