//problem link: https://www.interviewbit.com/problems/combination-sum-ii/

void backtrack(vector<int> &A, vector<vector<int>> &res, vector<int> &curr, int index, int target){
    if(target<0) return;
    if(target==0){
        res.push_back(curr);
        return;
    }
    for(int i=index;i<A.size();i++){
        if(i!=index && A[i]==A[i-1]) continue;
        curr.push_back(A[i]);
        backtrack(A,res,curr,i+1,target-A[i]);
        curr.pop_back();
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    vector<vector<int>> res;
    vector<int> curr;
    backtrack(A,res,curr,0,B);
    return res;
}
