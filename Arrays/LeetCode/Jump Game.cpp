//problem link: https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& A) {
        int n=A.size();
        int currMax=0, totalMax=0;
        for(int i=0;i<=totalMax;i++){
            if(A[i]>0) currMax=max(currMax,A[i]+i);
            if(currMax>=n-1) return true;
            if(i==totalMax){
                totalMax=currMax;
            }
        }
        return false;
    }
};