//problem link: https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:    
    int partition(vector<int> &nums, int lo, int hi){
        srand(time(0));
        swap(nums[hi],nums[lo+rand()%(hi-lo+1)]);
        int i=lo, pivot=nums[hi];
        for(int j=lo;j<hi;j++){
            if(nums[j]>=pivot){
                swap(nums[j],nums[i++]);
            }
        }
        swap(nums[i],nums[hi]);
        return i;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        int lo=0, hi=n-1;
        while(lo<=hi){
            int p=partition(nums,lo,hi);
            if(p<k-1) lo=p+1;
            else if(p>k-1) hi=p-1;
            else break;
        }
        return nums[k-1];
    }
};