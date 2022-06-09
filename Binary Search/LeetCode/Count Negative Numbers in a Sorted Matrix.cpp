//problem link: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int cnt=0;
        int row=0, col=n-1;
        while(row<m){
            while(col>=0 && grid[row][col]<0) col--;
            cnt+=(n-col-1);
            row++;
        }
        return cnt;
    }
};