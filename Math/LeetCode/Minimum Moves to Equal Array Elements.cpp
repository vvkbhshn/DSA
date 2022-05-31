//problem link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

class Solution {
public:
    int minMoves(vector<int>& nums) {        
        // sum + m*(n-1) = x*n (let x be the final equal array element, m=req. min moves)
        // x = minNum + m (since, minNum will always be the min number, and it will always be increased)
        // we get, [m = sum - n*minNum]
        
        int minNum=INT_MAX, sum=0;
        for(auto x:nums){
            minNum=min(minNum,x);
            sum+=x;
        }
        int n=nums.size();
        return sum-n*minNum;
    }
};