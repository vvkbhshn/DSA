//problem link: https://www.interviewbit.com/problems/search-in-bitonic-array/

int Solution::solve(vector<int> &arr, int B) {
    int n=arr.size();
    int l=0, r=n-1, mid;
    int idx=n-1;
    // find bitonic point k
    while(l<=r){
        mid=l+(r-l)/2;
        if((mid==0 || arr[mid]>arr[mid-1]) && (mid==n-1 || arr[mid]>arr[mid+1])){
            idx=mid;
            break;
        }
        else if(mid==0 || arr[mid]>arr[mid-1]) l=mid+1;
        else r=mid-1;
    }
    if(B>arr[idx]) return -1;
    if(B==arr[idx]) return idx;
    // check for target in the left part
    l=0; r=idx;
    while(l<=r){
        mid=l+(r-l)/2;
        if(arr[mid]<B) l=mid+1;
        else if(arr[mid]>B) r=mid-1;
        else return mid;
    }
    // check for target in the right part
    l=idx+1; r=n-1;
    while(l<=r){
        mid=l+(r-l)/2;
        if(arr[mid]>B) l=mid+1;
        else if(arr[mid]<B) r=mid-1;
        else return mid;
    }
    return -1;
}
