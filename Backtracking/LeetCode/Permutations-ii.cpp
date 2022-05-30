//problem link: https://leetcode.com/problems/permutations-ii/
// DIDNT understand, do once again

class Solution {
public:
    
    void findPermutations(vector<int> nums, vector<vector<int>> &res, int idx){
        if(idx==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            if(i!=idx && nums[i]==nums[idx]) continue;
            swap(nums[i],nums[idx]);
            findPermutations(nums,res,idx+1);
            // swap(nums[i],nums[idx]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        findPermutations(nums,res,0);
        return res;
    }

};