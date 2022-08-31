//problem link: https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
    int countPalindromes(string &s, int n, int l, int r){
        int res=0;
        while(l>=0 && r<n && s[l]==s[r]){
            l--;
            r++;
            res++;
        }
        return res;
    }
    
    int countSubstrings(string s) {
        int n=s.length();
        int res=0;
        for(int i=0;i<n;i++){
            res+=countPalindromes(s,n,i,i);
            res+=countPalindromes(s,n,i,i+1);
        }
        return res;
    }
};