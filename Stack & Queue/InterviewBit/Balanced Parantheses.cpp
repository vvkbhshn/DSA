//problem link: https://www.interviewbit.com/problems/balanced-parantheses/

int Solution::solve(string A) {
    stack<char> s;
    for(char c:A){
        if(c=='(') s.push(c);
        else{
            if(s.empty()) return 0;
            s.pop();
        }
    }
    return s.empty();
}
