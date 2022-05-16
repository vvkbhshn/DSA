// problem link: https://leetcode.com/problems/find-pivot-index/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int res=-1;
        int lsum=0,rsum=0;
        for(int i=0;i<nums.size();i++) rsum+=nums[i];
        for(int i=0;i<nums.size();i++){
            rsum-=nums[i];
            if(lsum==rsum){
                res=i;
                break;
            }
            lsum+=nums[i];
        }
        return res;
    }
};