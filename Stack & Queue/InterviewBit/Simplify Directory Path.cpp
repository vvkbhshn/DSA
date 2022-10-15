//problem link: https://www.interviewbit.com/problems/simplify-directory-path/

string Solution::simplifyPath(string A) {
    int n=A.length();
    int i=0;
    string temp, res;
    stack<string> s;
    while(i<n){
        temp.clear();
        while(i<n && A[i]=='/') i++;
        while(i<n && A[i]!='/') temp+=A[i++];
        if(temp==".") continue;
        else if(temp==".."){
            if(!s.empty()) s.pop();
        }
        else if(!temp.empty()) s.push(temp);                
    }
    stack<string> aux;
    while(!s.empty()){
        aux.push(s.top());
        s.pop();
    }
    while(!aux.empty()){
        res+="/"+aux.top();
        aux.pop();
    }
    if(res.empty()) res="/";
    return res;
}