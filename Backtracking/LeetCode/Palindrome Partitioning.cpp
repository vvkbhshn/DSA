//problem link: https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:    
    bool isPalindrome(string &s, int i, int j){
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    
    void findPartition(string &s, vector<vector<string>> &res, vector<string> &temp, int idx){
        int n=s.length();
        if(idx==n){
            res.push_back(temp);
            return;
        }
        for(int i=idx;i<s.length();i++){
            if(isPalindrome(s,idx,i)){
                temp.push_back(s.substr(idx,i-idx+1));
                findPartition(s,res,temp,i+1);
                temp.pop_back();
            }
        }        
    }    
    
    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<vector<string>> res;
        vector<string> temp;
        findPartition(s,res,temp,0);
        return res;       
    }
};