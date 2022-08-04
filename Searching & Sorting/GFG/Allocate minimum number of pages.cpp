//problem link: https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(M>N) return -1;
        int l=0,r=0, res=INT_MAX;
        for(int i=0;i<N;i++){
            l=max(l,A[i]);
            r+=A[i];
        }
        while(l<=r){
            int mid=l+(r-l)/2;
            int cnt=0, curr=0;
            for(int i=0;i<N;i++){
                if(curr+A[i]>mid){
                    cnt++;
                    curr=A[i];
                }
                else curr+=A[i];
            }
            cnt++;
            if(cnt<=M){
                res=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return res;
    }
};