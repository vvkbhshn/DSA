//problem link: https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int findCeil(vector<int> &dp, int num){
        int i=0, j=dp.size()-1;
        while(i<j){
            int mid=i+(j-i)/2;
            if(dp[mid]<num) i=mid+1;
            else j=mid;
        }
        return j;
    }    
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(), res=1;
        vector<int> dp;
        dp.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>dp.back()){
                dp.push_back(nums[i]);
            }
            else{
                int p=findCeil(dp,nums[i]);
                dp[p]=nums[i];
            }
        }
        return dp.size();
    }
};