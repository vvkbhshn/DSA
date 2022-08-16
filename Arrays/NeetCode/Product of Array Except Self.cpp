//problem link: https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int leftProd=1, rightProd=1;
        vector<int> res(n,1);
        for(int i=0;i<n;i++){
            res[i]*=leftProd;
            leftProd*=nums[i];
            res[n-1-i]*=rightProd;
            rightProd*=nums[n-1-i];
        }
        return res;
    }
};