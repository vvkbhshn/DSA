//problem link: https://leetcode.com/problems/next-greater-element-i/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> s;
        for(auto x:nums2){
            while(!s.empty() && s.top()<x){
                mp[s.top()]=x;
                s.pop();
            }
            s.push(x);
        }
        vector<int> res;
        for(auto x:nums1){
            if(mp.find(x)!=mp.end()) res.push_back(mp[x]);
            else res.push_back(-1);
        }
        return res;
    }
};