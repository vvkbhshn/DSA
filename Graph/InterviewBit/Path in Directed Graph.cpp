//problem link: https://www.interviewbit.com/problems/path-in-directed-graph/

int dfs(int u, int A, vector<int> adj[], vector<bool> &vis){
    vis[u]=true;
    if(u==A) return 1;
    for(auto v:adj[u]){
        if(!vis[v] && dfs(v,A,adj,vis)) return 1;
    }
    return 0;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> adj[A+1];
    vector<bool> vis(A+1,false);
    for(auto &edge: B) adj[edge[0]].push_back(edge[1]);
    return dfs(1,A,adj,vis);    
}
