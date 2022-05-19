//problem link: https://leetcode.com/problems/continuous-subarray-sum/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();        
        unordered_set<int>s;        
        int sum=0, pre=0;
        for(int i=0;i<n;i++){
            pre=sum;
            sum+=nums[i];
            if(k>0) sum=sum%k;
            if(s.find(sum)!=s.end()) return true;
            s.insert(pre);
        }
        return false;
    }
};