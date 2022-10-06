string Solution::solve(string A) {
    int n=A.length();
    stack<string> s;
    string curr;
    int i=0;
    while(i<n){
        if(A[i]==' ' && !curr.empty()){
            s.push(curr);
            curr.clear();
        }
        else if(A[i]!=' ') curr+=A[i];
        i++;
    }
    if(!curr.empty()) s.push(curr);
    string res;
    while(!s.empty()){
        res+=s.top()+" ";
        s.pop();
    }
    res.pop_back();
    return res;
}
