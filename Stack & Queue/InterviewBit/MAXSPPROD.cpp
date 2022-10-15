//problem link: https://www.interviewbit.com/problems/maxspprod/

int Solution::maxSpecialProduct(vector<int> &A) {
    int n=A.size();
    if(n<=2) return 0;
    long long res=0;
    vector<long long> prod(n,0);
    stack<long long> s;
    s.push(0);
    for(int i=1;i<n;i++){
        while(!s.empty() && A[i]>=A[s.top()]) s.pop();
        if(!s.empty()) prod[i]=s.top();
        s.push(i);
    }
    while(!s.empty()) s.pop();
    s.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(!s.empty() && A[i]>=A[s.top()]) s.pop();
        if(!s.empty()) prod[i]*=s.top();
        else prod[i]=0;
        s.push(i);
    }
    for(int i=1;i<n-1;i++) res=max(res,prod[i]); 
    return res%1000000007;
}
