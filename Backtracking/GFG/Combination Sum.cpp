//problem link: https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1

class Solution {
  public:
  
    void backtrack(vector<int> &arr, vector<vector<int>> &res, vector<int> &curr, int &B, int currSum, int idx){
        if(currSum>B) return;
        if(currSum==B){
            res.push_back(curr);
            return;
        }
        for(int i=idx;i<arr.size();i++){
            curr.push_back(arr[i]);
            backtrack(arr,res,curr,B,currSum+arr[i],i);
            curr.pop_back();
        }
    }
  
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        set<int> s(A.begin(),A.end());
        vector<int> arr;
        for(int x:s) arr.push_back(x);
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(arr,res,curr,B,0,0);
        return res;
    }
};