//problem link: https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int flag=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                flag=i;
                break;
            }
        }
        if(flag==-1){
            //arrange in sorted order
            int i=0, j=n-1;
            while(i<j){
                swap(nums[i++],nums[j--]);
            }
            return;
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[flag]){
                swap(nums[i],nums[flag]);
                break;
            }
        }
        reverse(nums.begin()+flag+1,nums.end());
    }
};