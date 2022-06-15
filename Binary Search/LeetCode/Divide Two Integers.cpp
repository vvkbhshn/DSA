//problem link: https://leetcode.com/problems/divide-two-integers/

class Solution {
public:
    int divide(int A, int B) {
        // A=dividend, B=divisor
        if(B==INT_MIN) return (A==INT_MIN);
        if(A==INT_MIN){
            if(B==-1) return INT_MAX;
            else if(B>0) return divide(A+B,B)-1;
            else if(B<0) return divide(A-B,B)+1;
        }        
        int a=A>0?A:-A;
        int b=B>0?B:-B;
        int res=0;
        while(a>=b){
            int n=0;
            while((b<<n)<=a && (b<<n)>0) ++n;
            --n;
            res+=1<<n;
            a-=(b<<n);
        }
        return (A>0)==(B>0) ? res: -res; 
     }
};