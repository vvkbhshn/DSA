//problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int flag=prices[0], res=0;
        for(int i=1;i<prices.size();i++){
            flag=min(flag,prices[i]);
            res=max(res,prices[i]-flag);
        }
        return res;
    }
};