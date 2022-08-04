//problem link: https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n=arr.size();
        int l=0, r=n-1, idx=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]<target){
                if(arr[mid]>arr[n-1] || target<=arr[n-1]) l=mid+1;
                else r=mid-1;
            }
            else if(arr[mid]>target){
                if(target>arr[n-1] || arr[mid]<=arr[n-1]) r=mid-1;
                else l=mid+1;
            }
            else return mid;
        }
        return -1;
    }
};