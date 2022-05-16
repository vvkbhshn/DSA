// problem link: https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int p=1;
        vector<int> res(n,1);
        for(int i=0;i<n;i++){
            res[i]=p;
            p*=nums[i];
        }
        p=1;
        for(int i=n-1;i>=0;i--){
            res[i]*=p;
            p*=nums[i];
        }
        return res;
    }
};