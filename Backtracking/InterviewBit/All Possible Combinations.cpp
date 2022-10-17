//problem link: https://www.interviewbit.com/problems/all-possible-combinations/

void backtrack(vector<string> &A, vector<string> &res, string &curr, int index){
    if(index==A.size()){
        res.push_back(curr);
        return;
    }
    for(int i=0;i<A[index].length();i++){
        curr+=A[index][i];
        backtrack(A,res,curr,index+1);
        curr.pop_back();
    }
}

vector<string> Solution::specialStrings(vector<string> &A) {
    vector<string> res;
    string curr;
    backtrack(A,res,curr,0);
    sort(res.begin(),res.end());
    return res;
}
