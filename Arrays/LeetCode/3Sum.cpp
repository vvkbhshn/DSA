//problem link: https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i+2<n;i++){
            int s=i+1, e=n-1;
            while(s<e){
                if(nums[s]+nums[e]==-nums[i]){
                    res.push_back({nums[i],nums[s],nums[e]});
                    while(s<e && nums[s+1]==nums[s]) s++;
                    while(s<e && nums[e-1]==nums[e]) e--;
                    s++;
                    e--;
                }
                else if(nums[s]+nums[e]<-nums[i]) s++;
                else e--;
            }
            while(i+1<n && nums[i+1]==nums[i]) i++;
        }
        return res;
    }
};