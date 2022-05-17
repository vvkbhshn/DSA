// problem link: https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    // bool binarySearch(vector<vector<int>>& matrix, int target, int i){
    //     int l=0, r=matrix[0].size()-1;
    //     while(l<=r){
    //         int mid=l+(r-l)/2;
    //         if(matrix[i][mid]>target) r=mid-1;
    //         else if(matrix[i][mid]<target) l=mid+1;
    //         else return true;
    //     }
    //     return false;
    // }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) { 

        // Binary Search: O(log(m*n)) time        
        int m=matrix.size(), n=matrix[0].size();
        int lo=0, hi=m*n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int temp=matrix[mid/n][mid%n];
            if(temp==target) return true;
            else if(target<temp) hi=mid-1;
            else lo=mid+1;
        }
        return false;

        // Binary search: O(mlog(n)) time
        // int m=matrix.size(), n=matrix[0].size();
        // for(int i=0;i<m;i++){
        //     if(matrix[i][0]<=target && matrix[i][n-1]>=target){
        //         if(binarySearch(matrix,target,i)) return true;
        //     }
        // }
        // return false;
    }
};