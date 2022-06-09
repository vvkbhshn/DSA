//problem link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    
    vector<int> search(vector<int> &arr, int l, int r, int target){
        if(arr[l]==target && arr[r]==target) return {l,r};
        if(arr[l]<=target && target<=arr[r]){
            int mid=l+(r-l)/2;
            vector<int> left=search(arr,l,mid,target);
            vector<int> right=search(arr,mid+1,r,target);
            if(left[0]!=-1 && right[0]!=-1) return {left[0],right[1]};
            return left[0]==-1 ? right : left;
        }
        return {-1,-1};
    }
    
    
    vector<int> searchRange(vector<int>& arr, int target) {
        
        // Method-1: [Divide and conquer]
        int n=arr.size();
        if(n==0) return {-1,-1};
        return search(arr,0,n-1,target);
        
        // Method-2: [Binary Search]
        // int n=arr.size(), x=-1, y=-1;
        // int l=0, r=n-1, mid;
        // while(l<=r){
        //     mid=l+(r-l)/2;
        //     if(arr[mid]==target && (mid==0 || arr[mid-1]!=target)){
        //         x=mid;
        //         break;
        //     }
        //     else if(arr[mid]<target) l=mid+1;
        //     else r=mid-1;
        // }
        // l=0; r=n-1;
        // while(l<=r){
        //     mid=l+(r-l)/2;
        //     if(arr[mid]==target && (mid==n-1 || arr[mid+1]!=target)){
        //         y=mid;
        //         break;
        //     }
        //     else if(arr[mid]<=target) l=mid+1;
        //     else r=mid-1;
        // }
        // return {x,y};
    }
};