//problem link: https://www.interviewbit.com/problems/magician-and-chocolates/

int Solution::nchoc(int A, vector<int> &B) {
    long long res=0, mod=1e9+7;
    priority_queue<int> pq(B.begin(),B.end());
    while(!pq.empty() && A>0){
        int x=pq.top();
        pq.pop();
        res=(res+x)%mod;
        if(x>1) pq.push(x/2);
        A--;
    }
    return res;
}
