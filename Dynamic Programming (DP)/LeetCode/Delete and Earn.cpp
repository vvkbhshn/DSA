//problem link: https://leetcode.com/problems/delete-and-earn/

class Solution {
public:    
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        int freq[10001]={0};
        for(auto x:nums) freq[x]++;
        int take=0, skip=0;
        for(int i=1;i<=10000;i++){
            int temp=max(skip+i*freq[i], take);
            skip=take;
            take=temp;
        }
        return take;
    }
};