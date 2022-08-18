//problem link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:        
    int lengthOfLongestSubstring(string s) {
        int maxLen=0, n=s.length();
        int i=0, j=0;
        unordered_map<char,int> letters;
        while(j<n){
            if(letters.find(s[j])!=letters.end()){
                i=max(i,1+letters[s[j]]);
            }
            letters[s[j]]=j;
            maxLen=max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};