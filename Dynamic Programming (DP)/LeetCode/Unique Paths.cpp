//problem link: https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Method-1: Combinatorics solution, O(n) or O(m) time
        // We make a total of m+n-2 moves, out of which (m-1) are downward moves,
        // and (n-1) are rightward moves.
        // Now the no. of rightward and downward moves vary depending on the path.
        // So, we need to choose either (m-1) or (n-1) moves out of (m+n-2) moves.
        // ans = (m+n-2)C(m-1) or, (m+n-2)C(n-1) [both will be equal, obviously]
        int N=m+n-2;
        int r=m-1;
        long long res=1;
        for(int i=1;i<=r;i++){
            res*=(long long)(N-r+i);
            res/=i;
        }
        return res;
        
        // Method-2: DP solution,  O(m*n) time and O(m*n) space
        // This can be further optimized to O(n) space since we only need values from previous row
        // vector<vector<int>> dp(m,vector<int>(n,1));
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(i && j) dp[i][j]=dp[i][j-1]+dp[i-1][j];
        //     }
        // }
        // return dp[m-1][n-1];
    }
};