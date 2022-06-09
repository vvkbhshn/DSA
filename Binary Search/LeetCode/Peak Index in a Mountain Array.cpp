//problem link: https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int l=0, r=n-1, mid;
        
        // Method-1:
        while(l<r){
            mid=l+(r-l)/2;
            if(arr[mid]<arr[mid+1]) l=mid+1;
            else r=mid;
        }
        return l;
        
        // Method-2:
        // while(l<=r){
        //     mid=l+(r-l)/2;
        //     if((mid==0 || arr[mid]>arr[mid-1]) && (mid==n-1 || arr[mid]>arr[mid+1])) return mid;
        //     else if(mid>0 && arr[mid]<=arr[mid-1]) r=mid-1;
        //     else l=mid+1;
        // }
        // return -1;
        
    }
};