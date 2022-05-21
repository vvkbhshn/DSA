//problem link: https://www.interviewbit.com/problems/maximum-sum-triplet/

int Solution::solve(vector<int> &A) {
    int n=A.size();
    int rMax[n];
    int res=0;
    rMax[n-1]=A[n-1];
    for(int i=n-2;i>=0;i--) rMax[i]=max(A[i],rMax[i+1]);
    set<int> s;
    s.insert(A[0]);
    for(int i=1;i<n-1;i++){
        s.insert(A[i]);
        if(rMax[i+1]>A[i]){
            auto it=s.find(A[i]);
            if(it!=s.begin()) res=max(res, (*--it)+A[i]+rMax[i+1]);
        }        
    }
    return res;
}
