//problem link: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> res;
        vector<bool> vis(V,false);
        queue<int> q;
        q.push(0);
        vis[0]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            res.push_back(node);
            for(auto x:adj[node]){
                if(!vis[x]){
                    vis[x]=true;
                    q.push(x);
                }
            }
        }
        return res;
    }
};