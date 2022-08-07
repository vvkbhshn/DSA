//problem link: https://practice.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1

class Solution {
  public:
  
    bool isPalindrome(string &str){
        int i=0, j=str.length()-1;
        while(i<j){
            if(str[i++]!=str[j--]) return false;
        }
        return true;
    }
  
    void backtrack(string &s, vector<vector<string>> &res, vector<string> &curr, int index){
        if(index==s.length()){
            res.push_back(curr);
            return;
        }
        string temp="";
        for(int i=index;i<s.length();i++){
            temp+=s[i];
            if(isPalindrome(temp)){
                curr.push_back(temp);
                backtrack(s,res,curr,i+1);
                curr.pop_back();
            }
        }
    }
  
    vector<vector<string>> allPalindromicPerms(string S) {
        vector<vector<string>> res;
        vector<string> curr;
        string s=S;
        backtrack(s,res,curr,0);
        return res;
    }
};