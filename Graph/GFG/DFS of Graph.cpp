//problem link: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution {
  public:  
    void dfs(int u, vector<int> adj[], vector<bool> &vis, vector<int> &res){
        res.push_back(u);
        for(auto v:adj[u]){
            if(!vis[v]){
                vis[v]=true;
                dfs(v,adj,vis,res);
            }
        }
    }
  
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> res;
        vector<bool> vis(V);
        vis[0]=true;
        dfs(0,adj,vis,res);
        return res;
    }
};