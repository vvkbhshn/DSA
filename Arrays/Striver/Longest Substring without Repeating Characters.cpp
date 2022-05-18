//problem link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        vector<int> mp(256,-1);
        int res=0;
        int l=0, r=0;
        while(r<n){
            if(mp[s[r]]!=-1){
                l=max(l,1+mp[s[r]]);
            }
            mp[s[r]]=r;
            res=max(res,r-l+1);
            r++;
        }
        return res;        
    }
};