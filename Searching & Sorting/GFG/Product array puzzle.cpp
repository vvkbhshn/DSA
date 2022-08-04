//problem link: https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1

class Solution{
  public:
    vector<long long int> productExceptSelf(vector<long long int>& arr, int n) {
        //code here     
        vector<long long int> res(n,1);
        long long int pre=1, suff=1;
        for(int i=0;i<n;i++){
            res[i]*=pre;
            pre*=arr[i];
            res[n-1-i]*=suff;
            suff*=arr[n-1-i];
        }
        return res;
    }
};