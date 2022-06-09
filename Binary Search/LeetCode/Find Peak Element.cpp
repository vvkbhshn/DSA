//problem link: https://leetcode.com/problems/find-peak-element/

class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n=arr.size();
        int l=0, r=n-1, mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if((mid==0 || arr[mid]>arr[mid-1]) && (mid==n-1 || arr[mid]>arr[mid+1])) return mid;
            else if(mid==0 || arr[mid]>arr[mid-1]) l=mid+1;
            else r=mid-1;
        }
        return -1;
    }
};