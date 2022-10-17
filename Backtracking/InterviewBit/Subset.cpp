//problem link: https://www.interviewbit.com/problems/subset/

void backtrack(vector<int> &A, vector<vector<int>> &res, vector<int> &curr, int index){
    res.push_back(curr);
    for(int i=index;i<A.size();i++){
        curr.push_back(A[i]);
        backtrack(A,res,curr,i+1);
        curr.pop_back();
    }
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    sort(A.begin(),A.end());
    vector<vector<int>> res;
    vector<int> curr;
    backtrack(A,res,curr,0);
    return res;
}
