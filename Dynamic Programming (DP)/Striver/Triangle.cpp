//problem link: https://leetcode.com/problems/triangle/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size(),n=triangle.back().size();
        vector<int> dp(n,INT_MAX);
        dp[0]=triangle[0][0];
        int prevCol=dp[0], prevRow=dp[1];
        for(int i=1;i<m;i++){
            prevCol=INT_MAX, prevRow=dp[0];
            dp[0]+=triangle[i][0];
            for(int j=1;j<=i;j++){
                swap(prevCol,prevRow);
                prevRow=dp[j];
                dp[j]=min(dp[j],prevCol)+triangle[i][j];
            }
        }
        return *min_element(dp.begin(),dp.end());
    }
};