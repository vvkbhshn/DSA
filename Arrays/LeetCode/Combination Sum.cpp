//problem link: https://leetcode.com/problems/combination-sum/

class Solution {
public:
    
    void findCombinations(vector<int>& candidates, vector<vector<int>>& res, vector<int> &temp,
                          int idx, int currSum, int &target){         
        if(currSum>target) return;
        if(currSum==target){
            res.push_back(temp);
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            findCombinations(candidates,res,temp,i,currSum+candidates[i],target);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        int n=candidates.size();
        vector<int> temp;
        findCombinations(candidates,res,temp,0,0,target);
        return res;
    }
};