//problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        int minPrice=prices[0];
        for(int i=1;i<prices.size();i++){
            res=max(res,prices[i]-minPrice);
            minPrice=min(minPrice,prices[i]);
        }
        return res;
    }
};