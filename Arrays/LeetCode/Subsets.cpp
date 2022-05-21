//problem link: https://leetcode.com/problems/subsets/submissions/

class Solution {
public:
    
    // BACKTRACKING
    void findSubsets(vector<int> &nums, vector<vector<int>> &res, vector<int> &temp, int idx){
        res.push_back(temp);       
        for(int i=idx;i<nums.size();i++){
            temp.push_back(nums[i]);
            findSubsets(nums,res,temp,i+1);
            temp.pop_back();
        }
    }    
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        findSubsets(nums,res,temp,0);
        return res;
    }
};