//problem link: https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        
        // Method-1:
        // for odd num, num^1 = num-1 and for even num, num^1 = num+1
        int n=arr.size();
        int l=0, r=n-2, mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if(arr[mid]==arr[mid^1]) l=mid+1;
            else r=mid-1;
        }
        return arr[l];
        
        // Method-2:
        // int n=arr.size();
        // int l=0, r=n-1, mid;
        // int res;
        // while(l<=r){
        //     mid=l+(r-l)/2;
        //     if((mid==0 || arr[mid]!=arr[mid-1]) && (mid==n-1 || arr[mid]!=arr[mid+1])) return arr[mid];
        //     else if(mid==0 || arr[mid]!=arr[mid-1]){
        //         if(mid%2==0) l=mid+1;
        //         else r=mid-1;
        //     }
        //     else{
        //         if(mid%2==1) l=mid+1;
        //         else r=mid-1;
        //     }
        // }
        // return -1;
    }
};