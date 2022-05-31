//problem link: https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Method-1
        int n=nums.size();
        int res=n;
        // {0^1^2^....^(n-1)^n}^{0^1^2^...^(x-1)^(x+1)^....^(n-1)^n} = x => missing number
        for(int i=0;i<n;i++){
            res^=i;
            res^=nums[i];
        }
        return res;
        
        // Method-2
        // int sum=0, n=nums.size();
        // for(auto x:nums) sum+=x;
        // return (n*(n+1))/2-sum;
    }
};