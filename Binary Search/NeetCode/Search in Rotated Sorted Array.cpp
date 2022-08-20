//problem link: https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size(), idx=-1;
        int lo=0, hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]<target){
                if(target<=nums[n-1] || nums[mid]>nums[n-1]) lo=mid+1;
                else hi=mid-1;
            }
            else if(nums[mid]>target){
                if(nums[mid]<=nums[n-1] || target>nums[n-1]) hi=mid-1;
                else lo=mid+1;
            }
            else{
                idx=mid;
                break;
            }
        }
        return idx;
    }
};