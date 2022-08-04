//problem link: https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int slow=arr[0], fast=arr[arr[0]];
        while(slow!=fast){
            slow=arr[slow];
            fast=arr[arr[fast]];
        }
        slow=0;
        while(slow!=fast){
            slow=arr[slow];
            fast=arr[fast];
        }
        return slow;
    }
};