//problem link: https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        int res=0;
        int i=0;
        bool neg=false;
        while(s[i]==' ') i++;
        if(s[i]=='-' || s[i]=='+') i++;
        if(i>0 && s[i-1]=='-') neg=true;
        while(i<n && (s[i]<='9' && s[i]>='0')){
            int x=(int)(s[i]-'0');
            if((res>INT_MAX/10) || (res==INT_MAX/10 && x>7)) return neg?INT_MIN: INT_MAX;
            res=res*10+x;
            i++;
        }
        return !neg?res:-res;
    }
};