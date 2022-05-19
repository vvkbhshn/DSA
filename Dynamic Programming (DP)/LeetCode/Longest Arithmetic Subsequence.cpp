//problem link: https://leetcode.com/problems/longest-arithmetic-subsequence/

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n=A.size();
        vector<vector<int>> dp(n,vector<int>(2001,0));
        int res=2;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                // [min Diff, max Diff] = [-1000, 1000]
                // add 1000 to diff range => [0, 2000]
                // thats why number of columns in 2000, and we add 1000 to A[j]-A[i]
                int diff=A[j]-A[i]+1000;
                dp[j][diff]=max(2,1+dp[i][diff]);
                res=max(res,dp[j][diff]);
            }
        }
        return res;
    }
};