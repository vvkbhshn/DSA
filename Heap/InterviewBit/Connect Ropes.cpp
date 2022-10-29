//problem link: https://www.interviewbit.com/problems/connect-ropes/

int Solution::solve(vector<int> &A) {
    int n=A.size();
    if(n==1) return 0;
    priority_queue<int,vector<int>,greater<int>> pq(A.begin(),A.end());
    int res=0;
    while(pq.size()>1){
        int x=pq.top(); pq.pop();
        int y=pq.top(); pq.pop();
        res+=(x+y);
        pq.push(x+y);
    }
    return res;
}