//problem link: https://www.interviewbit.com/problems/deserialize/

vector<string> Solution::deserialize(string A) {
    int n=A.length();
    vector<string> res;
    string len="";
    for(int i=0;i<n;i++){
        if(isdigit(A[i])) len+=A[i];
        else if(A[i]=='~'){
            int l=stoi(len);
            res.push_back(A.substr(i-l-len.length(),l));
            len.clear();
        }
    }
    return res;
}