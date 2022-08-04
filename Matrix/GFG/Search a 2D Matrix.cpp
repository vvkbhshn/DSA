//problem link: https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        int l=0, r=m*n-1, mid, x, y;
        while(l<=r){
            mid=l+(r-l)/2;
            x=mid/n;
            y=mid%n;
            if(matrix[x][y]<target) l=mid+1;
            else if(matrix[x][y]>target) r=mid-1;
            else return true;
        }
        return false;
    }
};