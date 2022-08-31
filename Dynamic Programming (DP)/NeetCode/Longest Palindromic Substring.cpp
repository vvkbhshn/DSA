//problem link: https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:    
    string longestPalindrome(string s) {
        int n=s.length();
        int maxLen=1, start=0;
        for(int i=0;i<n;i++){
            int l=i, r=i;
            while(l>=0 && s[l]==s[i]) l--;
            while(r<n && s[r]==s[i]) r++;
            while(l>=0 && r<n && s[l]==s[r]){
                l--;
                r++;
            }
            if(r-l-1>maxLen){
                maxLen=r-l-1;
                start=l+1;
            }
        }
        return s.substr(start,maxLen);
    }
};