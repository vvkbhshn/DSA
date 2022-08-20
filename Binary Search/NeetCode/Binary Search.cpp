//problem link: https://leetcode.com/problems/binary-search/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size(), idx=-1;
        int lo=0, hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]<target) lo=mid+1;
            else if(nums[mid]>target) hi=mid-1;
            else{
                idx=mid;
                break;
            }
        }
        return idx;
    }
};