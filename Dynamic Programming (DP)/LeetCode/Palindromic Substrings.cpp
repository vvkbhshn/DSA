//problem link: https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        int count=0;
        for(int i=0;i<n;i++){
            for(int l=i, r=i; l>=0 && r<n && s[l]==s[r]; l--, r++) count++; //odd length palindromes
            for(int l=i, r=i+1; l>=0 && r<n && s[l]==s[r]; l--, r++) count++; //even length palindromes
        }
        return count;
    }
};