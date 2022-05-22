//problem link: https://leetcode.com/problems/subarray-sums-divisible-by-k/

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int k) {
        int n=A.size();
        unordered_map<int,int> mp;
        mp[0]=1; //for the first time we met a subarray with remainder 0
        int sum=0, res=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
            int rem=sum%k;
            if(rem<0) rem+=k;
            res+=mp[rem];
            mp[rem]++;
        }
        return res;
    }
};