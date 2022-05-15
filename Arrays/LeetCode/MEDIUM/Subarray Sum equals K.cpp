//problem link: https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> prefix;
        int sum=0, res=0;
        prefix[0]=1; // we get 0 sum for empty subarray
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int temp=sum-k;
            if(prefix.find(temp)!=prefix.end()) res+=prefix[temp];
            prefix[sum]++;
        }
        return res;
    }
};