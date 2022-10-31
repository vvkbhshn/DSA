//problem link: https://leetcode.com/problems/minimum-falling-path-sum/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(2,vector<int>(n));
        dp[0]=matrix[0];
        int prev=0, curr=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int minSum=dp[prev][j];
                if(j>0) minSum=min(minSum,dp[prev][j-1]);
                if(j<n-1) minSum=min(minSum,dp[prev][j+1]);
                dp[curr][j]=matrix[i][j]+minSum;
            }
            swap(curr,prev);
        }
        return *min_element(dp[prev].begin(),dp[prev].end());
    }
};