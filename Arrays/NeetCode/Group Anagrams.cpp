//problem link: https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto s:strs){
            vector<int> freq(26,0);
            string temp="";
            for(auto c:s) freq[c-'a']++;
            for(auto x:freq){
                temp+=to_string(x)+" ";
            }
            mp[temp].push_back(s);
        }
        vector<vector<string>> res;
        for(auto it=mp.begin(); it!=mp.end(); it++){
            res.push_back(it->second);
        }
        return res;
    }
};