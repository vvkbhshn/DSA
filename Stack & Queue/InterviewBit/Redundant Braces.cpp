//problem link: https://www.interviewbit.com/problems/redundant-braces/

int Solution::braces(string A) {
    stack<char> s;
    bool mathOperator=false;
    for(int i=0;i<A.length();i++){
        if(A[i]==')'){
            int cnt=0;
            while(!s.empty() && s.top()!='('){
                char c=s.top();
                s.pop();
                if(c=='+' || c=='-' || c=='*' || c=='/') cnt++;
            }
            if(cnt==0) return 1;
            s.pop();
        }
        else s.push(A[i]);
    }
    return 0;
}
