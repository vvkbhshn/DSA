//problem link: https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int i=0, j=0, n=arr.size();
        int sum=0, res=INT_MAX;
        while(j<n){
            sum+=arr[j++];
            while(sum>=target){
                res=min(res,j-i);
                sum-=arr[i++];
            }
        }
        return (res==INT_MAX) ? 0 : res;
    }
};