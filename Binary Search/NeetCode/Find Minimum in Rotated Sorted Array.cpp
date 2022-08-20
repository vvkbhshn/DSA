//problem link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size(), idx=0;
        int lo=0, hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]<=nums[n-1]){
                idx=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return nums[idx];
    }
};