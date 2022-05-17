//problem link: https://leetcode.com/problems/powx-n/

class Solution {
public:
    double myPow(double x, int n) {
        //binary exponentiation: O(logn) time
        double res=1.0;
        int nn=abs(n);            
        while(nn){
            if(nn&1) res=res*x;
            x=x*x;
            nn/=2;
        }
        if(n<0) res=double(1)/res;
        return res;
    }
};