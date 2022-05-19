// problem link: https://leetcode.com/problems/maximum-product-subarray/submissions/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        
        // Method-1:
        int res=nums[0];
        for(int i=1, maxi=res, mini=res; i<n; i++){
            if(nums[i]<0) swap(maxi,mini);
            maxi=max(nums[i],maxi*nums[i]);
            mini=min(nums[i],mini*nums[i]);
            res=max(res,maxi);
        }
        return res;   
              
                      
        // Method-2:
        // If the negative numbers are even, then the first pass will give the solution
        // If the negative numbers are odd,  then the second pass will give the solution
        // int res=INT_MIN;
        // int prod=1;
        // for(int i=0;i<n;i++){
        //     prod*=nums[i];
        //     res=max(res,prod);
        //     if(prod==0) prod=1;
        // }
        // prod=1;
        // for(int i=n-1;i>=0;i--){
        //     prod*=nums[i];
        //     res=max(res,prod);
        //     if(prod==0) prod=1;
        // }
        // return res;
    }
};