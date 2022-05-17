//problem link: https://leetcode.com/problems/maximal-square/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();        
        vector<int> dp(n,0);
        int res=0, pre=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int temp=dp[j];
                if(i==0 || j==0 || matrix[i][j]=='0') dp[j]=matrix[i][j]-'0';
                else{
                    // since we only need the previous 3 elements.
                    dp[j]=1+min(pre,min(dp[j-1],dp[j]));
                }
                pre=temp;
                res=max(res,dp[j]);
            }
        }
        return res*res;
        
        // DP solution: O(m*n) space
        // vector<vector<int>> dp(m,vector<int>(n,0));
        // int res=0;
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(i==0 || j==0 || matrix[i][j]=='0') dp[i][j]=matrix[i][j]-'0';
        //         else dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
        //         res=max(res,dp[i][j]);
        //     }
        // }
        // return res*res;
    }
};