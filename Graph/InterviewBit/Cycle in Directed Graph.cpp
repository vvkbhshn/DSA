//problem link: https://www.interviewbit.com/problems/cycle-in-directed-graph/

bool dfs(int u, vector<int> adj[], vector<bool> &vis, vector<bool> &recStack){
    vis[u]=1;
    recStack[u]=1;
    for(auto v:adj[u]){
        if(!vis[v] && dfs(v,adj,vis,recStack)) return true;
        else if(recStack[v]) return true;
    }
    recStack[u]=0;
    return false;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    // Method-1: BFS (Kahn's algorithms)
    // vector<int> adj[A+1];
    // vector<int> indegree(A+1,0);
    // for(auto v:B){
    //     adj[v[0]].push_back(v[1]);
    //     indegree[v[1]]++;
    // }
    // int cnt=A;
    // queue<int> q;
    // for(int i=1;i<=A;i++) if(indegree[i]==0) q.push(i);
    // while(!q.empty()){
    //     int u=q.front();
    //     q.pop();
    //     cnt--;
    //     for(auto v:adj[u]){
    //         indegree[v]--;
    //         if(indegree[v]==0) q.push(v);
    //     }
    // }
    // return cnt>0; 
    
    // Method-2: DFS
    vector<int> adj[A+1];
    for(auto v:B) adj[v[0]].push_back(v[1]);
    vector<bool> vis(A+1,0), recStack(A+1,0);
    for(int i=1;i<=A;i++){
        if(!vis[i] && dfs(i,adj,vis,recStack)) return 1;
    }
    return 0;
}
