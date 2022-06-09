//problem link: https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        // Method-1:
        int n=nums.size();
        int l=0, r=n-1, mid;
        while(l<r){
            mid=l+(r-l)/2;
            // target and mid are on the same side
            if((nums[mid]-nums[n-1])*(target-nums[n-1])>0){
                if(nums[mid]<target) l=mid+1;
                else r=mid;
            }
            // target on the left side
            else if(target>nums[n-1]) r=mid;
            // target on the right side
            else l=mid+1;
        }
        return nums[l]==target ? l: -1;
        
        
        // Method-2:
        // find the pivot index k using binary search
        // binary search for target in [0,k] or [k+1,n-1]
        // int n=nums.size();
        // int k=n-1;
        // int l=0, r=n-1, mid;
        // while(l<=r){
        //     mid=l+(r-l)/2;
        //     if(nums[mid]>=nums[0]){
        //         k=mid;
        //         l=mid+1;
        //     }
        //     else r=mid-1;
        // }
        // // k=pivot index
        // if(k==n-1){l=0; r=n-1;}
        // else{
        //     if(target>=nums[0]) {l=0; r=k;}
        //     else {l=k+1; r=n-1;}
        // }
        // while(l<=r){
        //     mid=l+(r-l)/2;
        //     if(nums[mid]<target) l=mid+1;
        //     else if(nums[mid]>target) r=mid-1;
        //     else return mid;
        // }
        // return -1;
        
    }
};