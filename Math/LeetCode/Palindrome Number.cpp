//problem link: https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    
    int pow10(int n){
        int res=1;
        while(n--) res*=10;
        return res;
    }
    
    bool isPalindrome(int x) {
        if(x<0) return false;
        int pow=-1, temp=x;
        while(temp){
            pow++;
            temp/=10;
        }
        for(int p=pow;p>0;p-=2){
            if(x/pow10(p)!=x%10) return false;
            x=x%pow10(p);
            x/=10;
        }
        return true;
    }
};