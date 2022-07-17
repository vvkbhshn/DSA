//problem link: https://leetcode.com/problems/keys-and-rooms/

class Solution {
public:    
    void dfs(int node, vector<bool> &vis, vector<vector<int>> &adj){
        if(vis[node]) return;
        vis[node]=true;
        for(auto next:adj[node]){
            dfs(next,vis,adj);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> vis(n,false);
        dfs(0,vis,rooms);
        for(auto x:vis) if(x==false) return false;
        return true;
    }
};