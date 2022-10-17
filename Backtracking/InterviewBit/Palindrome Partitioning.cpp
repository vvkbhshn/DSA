//problem link: https://www.interviewbit.com/problems/palindrome-partitioning/

bool isPalindrome(string &A, int i, int j){
    while(i<j){
        if(A[i]!=A[j]) return false;
        i++;
        j--;
    }
    return true;
}

void backtrack(string &A, vector<vector<string>> &res, vector<string> &curr, int index){
    if(index==A.length()){
        res.push_back(curr);
        return;
    }
    for(int i=index;i<A.length();i++){
        if(isPalindrome(A,index,i)){
            curr.push_back(A.substr(index,i-index+1));
            backtrack(A,res,curr,i+1);
            curr.pop_back();
        }
    }
}

vector<vector<string>> Solution::partition(string A) {
    vector<vector<string>> res;
    vector<string> curr;
    backtrack(A,res,curr,0);
    return res;
}
