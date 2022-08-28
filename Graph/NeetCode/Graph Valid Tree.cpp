//problem link: https://www.codingninjas.com/codestudio/problems/graph-valid-tree_1376618

bool dfs(int node, int parent, vector<int> adj[], vector<bool> &vis){
    //return false if cycle exists
    vis[node]=true;
    for(auto next:adj[node]){
        if(!vis[next]){
            if(!dfs(next,node,adj,vis)) return false;
        }
        else if(next!=parent) return false;
    }
    return true;
}

// int doFind(int x, vector<int> &parent){
//     if(x!=parent[x]) parent[x]=doFind(parent[x],parent);
//     return parent[x];
// }

// void doUnion(int x, int y, vector<int> &parent, vector<int> &rank){
//     if(rank[x]<rank[y]) parent[x]=y;
//     else if(rank[y]<rank[x]) parent[y]=x;
//     else{
//         parent[y]=x;
//         rank[x]++;
//     }
// }

bool checkgraph(vector<vector<int>> edges, int n, int m)
{
    if(m!=n-1) return false;
    
    // Method-1: DFS cycle detection
    vector<int> adj[n];
    for(auto v:edges){
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
    }
    vector<bool> vis(n,false);
    if(!dfs(0,-1,adj,vis)) return false;
    for(int i=0;i<n;i++) if(!vis[i]) return false;
    return true;
    
    // Method-2: Union Find
    // vector<int> parent(n),rank(n,0);
    // vector<bool> vis(n,0);
    // for(int i=0;i<n;i++) parent[i]=i;
    // for(auto v:edges){
    //     vis[v[0]]=vis[v[1]]=1;
    //     int x=doFind(v[0],parent), y=doFind(v[1],parent);
    //     if(x==y) return false;
    //     else doUnion(x,y,parent,rank);
    // }
    // for(int i=0;i<n;i++) if(!vis[i]) return false;
    // return true;
}