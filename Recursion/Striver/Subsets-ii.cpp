//problem link: https://leetcode.com/problems/subsets-ii/

class Solution {
public:    
    void findSubsets(vector<int> &A, vector<vector<int>> &res, int n, vector<int> &temp, int idx){
        res.push_back(temp);
        for(int i=idx;i<n;i++){
           if(i==idx || A[i]!=A[i-1]){
               temp.push_back(A[i]);
               findSubsets(A,res,n,temp,i+1);
               temp.pop_back();
           } 
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        findSubsets(nums,res,n,temp,0);        
        return res;
    }
};