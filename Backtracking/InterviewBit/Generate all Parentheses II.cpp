//problem link: https://www.interviewbit.com/problems/generate-all-parentheses-ii/

void backtrack(int A, vector<string> &res, string &curr, int leftCount, int rightCount){
    if(leftCount==A && rightCount==A){
        res.push_back(curr);
        return;
    }
    if(leftCount>A) return;
    curr+='(';
    backtrack(A,res,curr,leftCount+1,rightCount);
    curr.pop_back();
    if(leftCount>rightCount){
        curr+=')';
        backtrack(A,res,curr,leftCount,rightCount+1);
        curr.pop_back();
    }
}

vector<string> Solution::generateParenthesis(int A){
    vector<string> res;
    string curr;
    backtrack(A,res,curr,0,0);
    return res;
}
