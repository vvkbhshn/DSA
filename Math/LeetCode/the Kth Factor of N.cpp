//problem link: https://leetcode.com/problems/the-kth-factor-of-n/

class Solution {
public:
    int kthFactor(int n, int k) {
        // Method-1: [O(sqrt(n)) time]
        double root=sqrt(n);
        for(int i=1;i<root;i++){
            if(n%i==0 && --k==0) return i;
        }
        for(int i=root;i>0;i--){
            if(n%i==0 && --k==0) return n/i;
        }
        return -1;
        
        // Method-2 [O(n) time]
        // int cnt=0;
        // for(int i=1;i<=n/2;i++) {
        //     if(n%i==0) cnt++;
        //     if(cnt==k) return i;
        // }
        // cnt++;
        // if(cnt==k) return n;
        // return -1;
    }
};