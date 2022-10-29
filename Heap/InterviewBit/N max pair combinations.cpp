//problem link: https://www.interviewbit.com/problems/n-max-pair-combinations/

struct myCmp{
    bool operator()(array<int,3> &a, array<int,3> &b){
        return a[0]<b[0];
    }
};

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    int n=A.size();
	vector<int> res;
	if(n==1) return {A[0]+B[0]};
    sort(A.rbegin(),A.rend());
    sort(B.rbegin(),B.rend());    
	unordered_map<int,unordered_set<int>> vis;
    priority_queue<array<int,3>,vector<array<int,3>>,myCmp> pq;
    pq.push({A[0]+B[0],0,0});
	vis[0].insert(0);
    while(!pq.empty() && res.size()<n){
        auto p=pq.top();
        pq.pop();
        int sum=p[0], i=p[1], j=p[2];
        res.push_back(sum);
        if(i<n-1 && vis[i+1].find(j)==vis[i+1].end()){
			pq.push({A[i+1]+B[j],i+1,j});
			vis[i+1].insert(j);
		}
		if(j<n-1 && vis[i].find(j+1)==vis[i].end()){
			pq.push({A[i]+B[j+1],i,j+1});
			vis[i].insert(j+1);
		}
    }
    return res;
}