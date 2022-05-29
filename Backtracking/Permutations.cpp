//problem link: https://leetcode.com/problems/permutations/

class Solution {
public:    
    void findPermutations(vector<int> &nums, vector<vector<int>> &res, int idx){
        if(idx==nums.size()) res.push_back(nums);
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            findPermutations(nums,res,idx+1);
            swap(nums[i],nums[idx]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        findPermutations(nums,res,0);
        return res;
    }
};