//problem link: https://www.interviewbit.com/problems/path-with-good-nodes/

int dfs(vector<int> &A, int &C, vector<int> adj[], int node, int parent, int count){    
    if(A[node-1]==1) count++;   
    if(count>C) return 0; 
    int res=0;
    for(auto next:adj[node]){
        if(next!=parent) res+=dfs(A,C,adj,next,node,count);
    }
    if(adj[node].size()==1 && adj[node][0]==parent && count<=C) res=1;
    return res;
}

int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
    int n=A.size();
    vector<int> adj[n+1];
    for(auto &v:B){
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
    }
    return dfs(A,C,adj,1,-1,0);
}	