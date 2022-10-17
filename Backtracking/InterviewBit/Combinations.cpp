//problem link: https://www.interviewbit.com/problems/combinations/

void backtrack(vector<vector<int>> &res, vector<int> &curr, int num, int n, int k){
    if(k==0){
        res.push_back(curr);
        return;
    }
    for(int i=num;i<=n;i++){
        curr.push_back(i);
        backtrack(res,curr,i+1,n,k-1);
        curr.pop_back();
    }
}

vector<vector<int> > Solution::combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> curr;
    backtrack(res,curr,1,n,k);
    return res;
}