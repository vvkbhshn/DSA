//problem link: https://www.interviewbit.com/problems/file-search/

void dfs(int u, vector<bool> &vis, vector<int> adj[]){
    vis[u]=true;
    for(auto v:adj[u]){
        if(!vis[v]){
            dfs(v,vis,adj);
        }
    }
}

int Solution::breakRecords(int A, vector<vector<int> > &B) {
    vector<int> adj[A+1];
    for(auto v:B){
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
    }
    int res=0;
    vector<bool> vis(A+1,false);
    for(int i=1;i<=A;i++){
        if(!vis[i]){
            dfs(i,vis,adj);
            res++;
        }
    }
    return res;
}
