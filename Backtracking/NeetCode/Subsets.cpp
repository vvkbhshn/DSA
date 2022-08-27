//problem link: https://leetcode.com/problems/subsets/

class Solution {
public:
    void findSubsets(vector<int> &nums, vector<vector<int>> &res, vector<int> &curr, int index){
        res.push_back(curr);
        for(int i=index;i<nums.size();i++){
            curr.push_back(nums[i]);
            findSubsets(nums,res,curr,i+1);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        findSubsets(nums,res,curr,0);
        return res;
    }
};