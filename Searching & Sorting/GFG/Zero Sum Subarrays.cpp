//problem link: https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        ll res=0,currSum=0;
        unordered_map<ll,ll> mp;
        mp[0]=1;
        for(int i=0;i<n;i++){
            currSum+=arr[i];
            res+=mp[currSum];
            mp[currSum]++;
        }
        return res;
    }
};