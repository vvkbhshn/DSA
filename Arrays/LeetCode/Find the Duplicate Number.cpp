//problem link: https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //Floyd's cycle detection algorithm
        int slow=nums[0], fast=nums[nums[0]];
        //cycle detection
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        slow=0;
        //find the entry point of the circle,  which is the repeating element
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};