//problem link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

class Solution {
  public:
    bool dfs(int u, vector<int> adj[], vector<bool> &vis, vector<bool> &recStack){
        vis[u]=1;
        recStack[u]=1;
        for(auto v:adj[u]){
            if(!vis[v] && dfs(v,adj,vis,recStack)==true) return true;
            else if(recStack[v]==1) return true;
        }
        recStack[u]=0;
        return false;
    }
    
    bool bfs(int V, vector<int> adj[]){
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto x:adj[i]) indegree[x]++;
        }
        queue<int> q;
        for(int i=0;i<V;i++) if(indegree[i]==0) q.push(i);
        int cnt=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            cnt++;
            for(auto v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }
        }
        return cnt!=V;
    }
  
    bool isCyclic(int V, vector<int> adj[]) {
        // Method-1: DFS
        // vector<bool> vis(V,0);
        // vector<bool> recStack(V,0);
        // for(int i=0;i<V;i++){
        //     if(!vis[i] && dfs(i,adj,vis,recStack)==true) return true;
        // }
        // return false;
        
        //Method-2: BFS (kahn's algorithm)
        return bfs(V,adj);
    }
};