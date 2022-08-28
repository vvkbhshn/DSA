//problem link: https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    
    // bool dfs(int course, vector<int> adj[], vector<bool> &vis, vector<bool> &recStk, vector<int> &res){
    //     vis[course]=1;
    //     recStk[course]=1;
    //     for(auto next:adj[course]){
    //         if(!vis[next] && !dfs(next,adj,vis,recStk,res)) return false;
    //         else if(recStk[next]) return false;
    //     }
    //     recStk[course]=0;
    //     res.push_back(course);
    //     return true;
    // }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        // Method-1: topSort(Kahn's algorithm)
        vector<int> res;
        vector<int> indegree(numCourses,0);
        vector<int> adj[numCourses];
        for(auto v:prerequisites){
            adj[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++) if(indegree[i]==0) q.push(i);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            res.push_back(u);
            for(auto v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }
        }
        if(res.size()!=numCourses) return {};
        return res;
        
        // Method-2:DFS
        // vector<int> res;
        // vector<bool> vis(numCourses,0), recStk(numCourses,0);
        // vector<int> adj[numCourses];
        // for(auto v:prerequisites){
        //     adj[v[1]].push_back(v[0]);
        // }
        // for(int i=0;i<numCourses;i++){
        //     if(!vis[i] && !dfs(i,adj,vis,recStk,res)) return {};
        // }
        // reverse(res.begin(),res.end());
        // return res;
    }
};