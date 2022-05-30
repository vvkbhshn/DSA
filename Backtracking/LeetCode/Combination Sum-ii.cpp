//problem link: https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:    
    void findCombinations(vector<int> &candidates, vector<vector<int>> &res, vector<int> &temp, int target, int idx){
        if(target<0) return;
        if(target==0){
            res.push_back(temp);
            return;
        }
        for(int i=idx;i<candidates.size() && target>=candidates[i];i++){
            if(i==idx || candidates[i]!=candidates[i-1]){
                temp.push_back(candidates[i]);
                findCombinations(candidates,res,temp,target-candidates[i],i+1);
                temp.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        findCombinations(candidates,res,temp,target,0);
        return res;
    }
};