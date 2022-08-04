//problem link: https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n=arr.size(),i,j;
        for(i=n-2;i>=0;i--){
            if(arr[i]<arr[i+1]) break;
        }
        if(i==-1){
            reverse(arr.begin(),arr.end());
            return;
        }
        int l=i+1, r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]>arr[i]){
                j=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        swap(arr[i],arr[j]);
        reverse(arr.begin()+i+1,arr.end());
    }
};