//problem link: https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    // int findDepth(unordered_map<int,int> &mp, int num){
    //     if(mp[num]==0) return 0;
    //     if(mp[num]>1) return mp[num];
    //     return mp[num]=1+findDepth(mp,num-1);
    // }
    
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        
        // Method-1: O(n) time
        unordered_set<int> s(nums.begin(),nums.end());
        int res=0;
        for(auto x:s){
            if(s.find(x-1)==s.end()){
                //if(s.find(x-1)==s.end()) checks for the first element in a sequence
                int y=x+1;
                while(s.find(y)!=s.end()) y++;
                res=max(res,y-x);
            }
        }
        return res;
        
        // Method-2:
        // unordered_map<int,int> mp;
        // for(auto x:nums) mp[x]=1;
        // int res=0;
        // for(auto x:nums){
        //     if(mp[x]==1) res=max(res,findDepth(mp,x));
        // }
        // return res;
    }
};