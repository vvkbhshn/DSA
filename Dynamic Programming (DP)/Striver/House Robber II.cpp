//problem link: https://leetcode.com/problems/house-robber-ii/

class Solution {
public:    
    int robHouse(vector<int> &nums, int start, int end){
        int prev2=0, prev=0, curr=0;
        for(int i=start;i<=end;i++){
            curr=max(nums[i]+prev2,prev);
            prev2=prev;
            prev=curr;
        }
        return curr;
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int res1=robHouse(nums,0,n-2); //house 1 is robbed
        int res2=robHouse(nums,1,n-1); //house 1 is not robbed
        return max(res1,res2);
    }
};