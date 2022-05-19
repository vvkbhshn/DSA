//problem link: https://leetcode.com/problems/longest-increasing-subsequence/submissions/

class Solution {
public:    
    int findCeil(int dp[], int num, int n){
        int l=0, r=n-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(dp[mid]<num) l=mid+1;
            else r=mid;
        }
        return r;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int dp[n]; 
        //dp[i] represents the minimum last element of the increasing subsequence with length i+1
        int len=1;
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>dp[len-1]) dp[len++]=nums[i];
            else{
                int c=findCeil(dp,nums[i],len);
                dp[c]=nums[i];
            }
        }
        return len;
    }
};