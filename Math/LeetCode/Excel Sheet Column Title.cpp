//problem link: https://leetcode.com/problems/excel-sheet-column-title/

class Solution {
public:
    string convertToTitle(int n) {
        if(n==0) return "";
        string temp="";
        temp=(char)((n-1)%26 + 'A');
        return convertToTitle((n-1)/26)+temp;
    }
};