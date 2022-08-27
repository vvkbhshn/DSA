//problem link: https://leetcode.com/problems/combination-sum/

class Solution {
public:    
    void findCombinations(vector<int>& candidates, vector<vector<int>> &res,vector<int> &curr, int target, int index){        
        if(target<0) return;
        if(target==0){
            res.push_back(curr);
            return;
        }              
        for(int i=index;i<candidates.size();i++){
            curr.push_back(candidates[i]);
            findCombinations(candidates,res,curr,target-candidates[i],i);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        findCombinations(candidates,res,curr,target,0);
        return res;
    }
};