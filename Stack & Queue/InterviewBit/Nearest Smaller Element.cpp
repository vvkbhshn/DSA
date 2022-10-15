//problem link: https://www.interviewbit.com/problems/nearest-smaller-element/

vector<int> Solution::prevSmaller(vector<int> &A) {
    int n=A.size();
    vector<int> res(n,-1);
    stack<int> s;
    for(int i=0;i<n;i++){
        while(!s.empty() && s.top()>=A[i]) s.pop();
        res[i]=(s.empty() ? -1: s.top());
        s.push(A[i]);
    }
    return res;
}
