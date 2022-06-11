//problem link: https://www.interviewbit.com/problems/rotated-sorted-array-search/

int Solution::search(const vector<int> &arr, int B) {
    int n=arr.size();
    int l=0, r=n-1, mid;
    while(l<=r){
        mid=l+(r-l)/2;
        if((long long)(arr[mid]-arr[n-1])*(B-arr[n-1])>0){
            // mid and B on the same side
            if(arr[mid]<B) l=mid+1;
            else if(arr[mid]>B) r=mid-1;
            else return mid;
        }
        else if(B>arr[n-1]) r=mid-1;          
        else l=mid+1;
    }
    return -1;
}
