//problem link: https://leetcode.com/problems/generate-parentheses/

class Solution {
public:    
    void generate(int n, int open, int close, string &curr, vector<string> &res){
        if(open==n && close==n){
            res.push_back(curr);
            return;
        }
        if(open<n){
            curr+='(';
            generate(n,open+1,close,curr,res);
            curr.pop_back();
        }
        if(open>close){
            curr+=')';
            generate(n,open,close+1,curr,res);
            curr.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr="";
        generate(n,0,0,curr,res);
        return res;
    }
};