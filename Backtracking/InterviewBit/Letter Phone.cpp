//problem link: https://www.interviewbit.com/problems/letter-phone/

void backtrack(vector<string> &phone, string &A, vector<string> &res, string &curr, int index){
    if(index==A.length()){
        res.push_back(curr);
        return;
    }
    for(char c:phone[A[index]-'0']){
        curr.push_back(c);
        backtrack(phone,A,res,curr,index+1);
        curr.pop_back();
    }
}

vector<string> Solution::letterCombinations(string A) {
    vector<string> phone={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> res;
    string curr;
    backtrack(phone,A,res,curr,0);
    return res;
}
