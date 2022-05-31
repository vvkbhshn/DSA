//problem link: https://leetcode.com/problems/happy-number/

class Solution {
public:
    
    int digitSquareSum(int n){
        int sum=0;
        while(n){
            sum+=(n%10)*(n%10);
            n/=10;
        }
        return sum;
    }
    
    bool isHappy(int n) {        
        // Method-1 (cycle detection)
        // If it is an infinite loop then a cycle will be formed and we can use 
        // Floyd cycle detection method to determine it
        
        int slow=digitSquareSum(n);
        int fast=digitSquareSum(digitSquareSum(n));
        while(slow!=fast){
            slow=digitSquareSum(slow);
            fast=digitSquareSum(digitSquareSum(fast));
        }
        return (slow==1);
        
        // Method-2 (by hit and trial method)
        // if(n==1 || n==7) return true;
        // if(n<10) return false;
        // int res=0;
        // while(n){
        //     res+=(n%10)*(n%10);
        //     n/=10;
        // }
        // return isHappy(res);
    }
};