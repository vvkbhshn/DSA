//problem link: https://www.interviewbit.com/problems/permutations/

void backtrack(vector<int> &A, vector<vector<int>> &res, int index){
    if(index==A.size()){
        res.push_back(A);
        return;
    }
    for(int i=index;i<A.size();i++){
        if(i>index && A[i]==A[index]) continue;
        swap(A[index],A[i]);
        backtrack(A,res,index+1);
        swap(A[index],A[i]);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> res;
    backtrack(A,res,0);
    return res;
}