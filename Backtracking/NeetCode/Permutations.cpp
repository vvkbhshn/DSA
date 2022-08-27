//problem link: https://leetcode.com/problems/permutations/

class Solution {
public:    
    void findPermutations(vector<int> &nums, vector<vector<int>> &res, int index){
        if(index==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            findPermutations(nums,res,index+1);
            swap(nums[i],nums[index]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        findPermutations(nums,res,0);
        return res;
    }
};