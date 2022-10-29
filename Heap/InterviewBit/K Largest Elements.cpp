//problem link: https://www.interviewbit.com/problems/k-largest-elements/

int quickSelect(vector<int> &A, int left, int right){
    int pivot=A[right];
    int index=left;
    for(int i=left;i<right;i++){
        if(A[i]>pivot) swap(A[index++],A[i]);
    }
    swap(A[index],A[right]);
    return index;
}

vector<int> Solution::solve(vector<int> &A, int k) {
    // Method-1: QuickSelect=> O(n) time avg.
    int n=A.size();
    vector<int> res;
    int lo=0, hi=n-1;
    while(lo<=hi){
        int p=quickSelect(A,lo,hi);
        if(p==k-1) break;
        else if(p<k-1) lo=p+1;
        else hi=p-1;
    }
    for(int i=0;i<k;i++) res.push_back(A[i]);
    return res;
    
    // Method-2:
    // vector<int> res;
    // priority_queue<int,vector<int>,greater<int>> pq;
    // for(auto x:A){
    //     pq.push(x);
    //     if(pq.size()>k) pq.pop();
    // }
    // while(!pq.empty()){
    //     res.push_back(pq.top());
    //     pq.pop();
    // }
    // return res;
}
