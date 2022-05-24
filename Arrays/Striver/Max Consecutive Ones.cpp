//problem link: https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& A) {
        int res=0, count=0;
        for(int i=0;i<A.size();i++){
            if(A[i]==1){
                count++;
                res=max(res,count);
            }
            else count=0;
        }
        return res;
    }
};