//problem link: https://www.interviewbit.com/problems/largest-rectangle-in-histogram/

int Solution::largestRectangleArea(vector<int> &A) {
    // Method-1:
    A.push_back(-1);
    int n=A.size();
    int res=0;
    stack<int> s;
    for(int i=0;i<n;i++){
        while(!s.empty() && A[s.top()]>A[i]){
            int height=A[s.top()];
            s.pop();
            int width=i;
            if(!s.empty()) width=i-s.top()-1;
            res=max(res,height*width);
        }
        s.push(i);
    }
    return res;
    
    //Method-2:
    // int n=A.size();
    // int res=0;
    // vector<int> left(n),right(n);
    // stack<int> s;
    // for(int i=0;i<n;i++){
    //     while(!s.empty() && A[s.top()]>=A[i]) s.pop();
    //     if(!s.empty()) left[i]=s.top();
    //     else left[i]=-1;
    //     s.push(i);
    // }
    // while(!s.empty()) s.pop();
    // for(int i=n-1;i>=0;i--){
    //     while(!s.empty() && A[s.top()]>=A[i]) s.pop();
    //     if(!s.empty()) right[i]=s.top();
    //     else right[i]=n;
    //     s.push(i);
    // }
    // for(int i=0;i<n;i++) res=max(res,A[i]*(right[i]-left[i]-1));
    // return res;
}