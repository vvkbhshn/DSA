//problem link: https://leetcode.com/problems/concatenated-words/
//TO TRY WITH DP & TRIE

class Solution {
public:
    
    bool dfs(string &word, int l, int r, unordered_set<string> &st){ 
        if(l>r) return true;
        string curr="";
        for(int i=l;i<=r;i++){
            curr+=word[i];
            if(st.find(curr)!=st.end()){
                if(l==0 and i==r) continue;
                if(dfs(word,i+1,r,st)) return true;
            }
        }
        return false;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        int n=words.size();
        unordered_set<string> st(words.begin(),words.end());
        for(int i=0;i<n;i++){
            if(dfs(words[i],0,words[i].length()-1,st)) res.push_back(words[i]);
        }
        return res;
    }
};