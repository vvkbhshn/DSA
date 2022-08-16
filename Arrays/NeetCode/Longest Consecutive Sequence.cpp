//problem link: https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res=0;
        unordered_set<int> s(nums.begin(), nums.end());
        for(auto x:nums){
            if(s.find(x-1)==s.end()){
                int y=x+1;
                while(s.find(y)!=s.end()) y++;
                res=max(res,y-x);
            }
        }
        return res;
    }
};