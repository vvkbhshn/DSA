//problem link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

class Solution {
  public:  
    bool dfs(int node, int parent, vector<int> adj[], vector<bool> &vis){
        vis[node]=1;
        for(auto x:adj[node]){
            if(!vis[x]){
                if(dfs(x,node,adj,vis)==true) return true;
            }
            else if(x!=parent) return true;
        }
        return false;
    }
    
    bool bfs(int node, vector<int> adj[], vector<bool> &vis){
        queue<pair<int,int>> q;
        q.push({node,-1});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int u=p.first, parent=p.second;
            vis[u]=true;
            for(auto v:adj[u]){
                if(!vis[v]) q.push({v,u});
                else if(v!=parent) return true;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V,0);
        
        // Method-1: DFS
        for(int i=0;i<V;i++){
            if(!vis[i] && dfs(i,-1,adj,vis)) return true;
        }
        
        // Method-2: BFS
        // for(int i=0;i<V;i++){
        //     if(!vis[i] && bfs(i,adj,vis)) return true;
        // }
        
        return false;
    }
};