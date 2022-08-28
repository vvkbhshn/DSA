//problem link: https://leetcode.com/problems/house-robber/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();        
        int prev=0, curr=0, next=0;
        //prev=max money at (i-2)th house
        //curr=max money at (i-1)th house
        for(int i=0;i<n;i++){
            next=max(nums[i]+prev,curr);
            prev=curr;
            curr=next;
        }
        return curr;
    }
};