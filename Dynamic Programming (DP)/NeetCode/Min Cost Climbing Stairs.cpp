//problem link: https://leetcode.com/problems/min-cost-climbing-stairs/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int a=0, b=0;
        for(int i=2;i<=n;i++){
            int temp=b;
            b=min(cost[i-1]+b,cost[i-2]+a);
            a=temp;
        }
        return b;
    }
};