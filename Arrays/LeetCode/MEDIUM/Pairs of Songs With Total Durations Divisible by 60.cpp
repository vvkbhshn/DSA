//problem link: https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        long long arr[60]={0};
        for(auto x:time) arr[x%60]++;
        long long res=0;
        for(int i=1;i<30;i++) res+=arr[i]*arr[60-i];
        res+=(arr[0]*(arr[0]-1))/2;
        res+=(arr[30]*(arr[30]-1))/2;
        return res;
    }
};