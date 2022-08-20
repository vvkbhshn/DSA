//problem link: https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        int lo=0, hi=m*n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int x=mid/n, y=mid%n;
            if(matrix[x][y]<target) lo=mid+1;
            else if(matrix[x][y]>target) hi=mid-1;
            else return true;
        }
        return false;
    }
};