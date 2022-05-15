//problem link: https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size(), ans=0;
        for(int i=0;i<n;i++){
            nums[(nums[i]%n)-1]+=n;
        }
        for(int i=0;i<n-1;i++){
            if(nums[i]/n>1){
                ans=i+1;
                break;
            }
        }
        return ans;
    }
};