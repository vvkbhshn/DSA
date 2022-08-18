//problem link: https://leetcode.com/problems/permutation-in-string/

class Solution {
public:    
    bool isPermutation(int freq[]){
        for(int i=0;i<26;i++){
            if(freq[i]!=0) return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int m=s1.length(), n=s2.length();
        if(m>n) return false;
        int freq[26]={0};
        for(int i=0;i<m;i++){
            freq[s1[i]-'a']++;
            freq[s2[i]-'a']--;
        }
        if(isPermutation(freq)) return true;
        for(int i=m;i<n;i++){
            freq[s2[i]-'a']--;
            freq[s2[i-m]-'a']++;
            if(isPermutation(freq)) return true;
        }
        return false;
    }
};