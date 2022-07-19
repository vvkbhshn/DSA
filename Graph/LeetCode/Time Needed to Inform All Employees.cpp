//problem link: https://leetcode.com/problems/time-needed-to-inform-all-employees/submissions/

class Solution {
public:
    
    int dfs(int node, vector<int> &informTime, unordered_map<int,vector<int>> &adj){
        int res=0;
        for(int next:adj[node]){
            res=max(res,dfs(next,informTime,adj));
        }
        return res+informTime[node];
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<n;i++) if(i!=headID) adj[manager[i]].push_back(i);
        
        // Method-1: DFS
        return dfs(headID,informTime,adj);
        
        // Method-2: BFS
        // int res=0;
        // queue<pair<int,int>> q;
        // q.push({headID,0});
        // while(!q.empty()){
        //     auto p=q.front();
        //     int u=p.first, time=p.second;
        //     q.pop();
        //     res=max(res,time);
        //     for(auto v:adj[u]) q.push({v,time+informTime[u]});
        // }
        // return res;
    }
};