//problem link: https://www.interviewbit.com/problems/profit-maximisation/

int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        pq.push(A[i]);
    }
    int res=0;
    while(B--){
        int numOfSeats=pq.top();
        pq.pop();
        if(numOfSeats==0) break;
        res+=numOfSeats;
        pq.push(numOfSeats-1);
    }
    return res;
}
