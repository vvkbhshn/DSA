//problem link: https://leetcode.com/problems/find-eventual-safe-states/

class Solution {
public:
    
    void dfs(int u, vector<bool> &vis, vector<bool> &recVis, vector<bool> &safe, vector<vector<int>> &graph){
        
        vis[u]=true;
        recVis[u]=true;
        
        for(auto v:graph[u]){
            if(!vis[v]){
                //unvisited node
                dfs(v,vis,recVis,safe,graph);
                if(!safe[v]) safe[u]=false;
            } 
            else{
                if(!safe[v]){
                    //unsafe node
                    safe[u]=false;
                }
                else if(recVis[v]){
                    //cycle detected
                    safe[u]=safe[v]=false;
                }
            }
        }
        
        recVis[u]=false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> res;
        vector<bool> vis(n,false);
        vector<bool> recVis(n,false);
        vector<bool> safe(n,true);
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(i,vis,recVis,safe,graph);
        }
        for(int i=0;i<n;i++) if(safe[i]) res.push_back(i);
        return res;
    }
};