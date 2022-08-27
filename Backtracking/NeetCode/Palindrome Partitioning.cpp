//problem link: https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:    
    bool isPalindrome(string &str, int i, int j){
        while(i<j){
            if(str[i++]!=str[j--]) return false;
        }
        return true;
    }
    
    void findPalindromes(string &s, vector<vector<string>> &res, vector<string> &curr, int index){
        if(index==s.length()){
            res.push_back(curr);
            return;
        }
        for(int i=index;i<s.length();i++){
            if(isPalindrome(s,index,i)){
                curr.push_back(s.substr(index,i-index+1));
                findPalindromes(s,res,curr,i+1);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        findPalindromes(s,res,curr,0);
        return res;
    }
};