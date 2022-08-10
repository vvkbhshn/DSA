//problem link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/submissions/

class Solution {
public:       
    void dfs(int node, vector<int> adj[], vector<bool> &vis){
        if(vis[node]) return;
        vis[node]=1;
        for(auto next:adj[node]) dfs(next,adj,vis);
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<bool> vis(n,0);
        vector<int> adj[n];
        for(auto v:connections){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        int connectedComponents=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                connectedComponents++;
            }
        }
        int k=connections.size();
        if(k<n-1) return -1;
        return connectedComponents-1;        
    }
};