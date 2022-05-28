//problem link: https://leetcode.com/problems/word-break-ii/

class Solution {
public:         
    vector<string> solve(string &s, unordered_set<string> &dict, 
                         unordered_map<int,vector<string>> &hmap, int &maxLen, int idx){ 
        
        if(hmap.find(idx)!=hmap.end()) return hmap[idx];
        string temp;
        for(int i=idx; i<s.length() && temp.length()<maxLen; i++){
            temp+=s[i];
            if(dict.find(temp)!=dict.end()){
                if(i==s.length()-1) hmap[idx].push_back(temp);
                else{
                    vector<string> v=solve(s,dict,hmap,maxLen,i+1);
                    for(auto &x:v) hmap[idx].push_back(temp+" "+x);
                }                
            }
        }
        return hmap[idx];
    }
    
    // void solve2(string &s, unordered_set<string> &hmap, vector<string> &res, string str, int idx){
    //     int n=s.length();
    //     if(idx==n){
    //         res.push_back(str);
    //         return;
    //     }        
    //     for(int i=1;i+idx<=n;i++){
    //         string temp=s.substr(idx,i);
    //         if(hmap.find(temp)!=hmap.end()){
    //             if(str.empty()) solve2(s,hmap,res,str+temp,i+idx);
    //             else solve2(s,hmap,res,str+" "+temp,i+idx);
    //         }
    //     }             
    // }
    
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        // Method-1: [top-down DP + memoization]
        vector<string> res;
        unordered_set<string> dict;
        int maxLen=0;
        for(auto &x: wordDict){
            dict.insert(x);
            maxLen=max(maxLen,(int)x.length());
        }
        unordered_map<int,vector<string>> hmap;
        return solve(s,dict,hmap,maxLen,0);           
        
        // Method-2: [bottom-up DP]
        // vector<string> res;
        // unordered_set<string> hmap(wordDict.begin(),wordDict.end());             
        // solve2(s,hmap,res,"",0);
        // return res;        
    }
};