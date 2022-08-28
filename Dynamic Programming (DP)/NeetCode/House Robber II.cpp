//problem link: https://leetcode.com/problems/house-robber-ii/

class Solution {
public:
    int solve(vector<int> &nums, int start, int end){
        int prev=0, curr=0, next=0;
        for(int i=start;i<=end;i++){
            next=max(nums[i]+prev,curr);
            prev=curr;
            curr=next;
        }
        return curr;
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int ans1=solve(nums,0,n-2); // house 1 is robbed
        int ans2=solve(nums,1,n-1); // house 1 is NOT robbed
        return max(ans1,ans2);
    }
};