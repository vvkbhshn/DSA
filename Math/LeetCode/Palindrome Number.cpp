//problem link: https://leetcode.com/problems/palindrome-number/

class Solution {
public:    
    bool isPalindrome(int A) {
        // Method-1:
        if(A<0) return 0;
        if(A==0) return 1;
        int pow=log10(A);
        int pow10=1, p=pow;
        while(p--) pow10*=10;
        for(int i=pow; i>0 && A>0; i-=2){
            //compare first and last digits
            if(A/pow10!=A%10) return 0;
            A%=pow10;
            A/=10;
            pow10/=100; 
        }
        return 1;

        // Method-2: (calculate the reverse integer and compare with the original)
        // if(A<0) return 0;
        // long long temp=0, x=A;
        // while(x){
        //     temp=temp*10+x%10;
        //     x/=10;
        // }
        // if(temp==A) return 1;
        // return 0;
    }
};