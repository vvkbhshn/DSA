//problem link: https://leetcode.com/problems/course-schedule/

class Solution {
public:
    
    // bool dfs(int course, vector<int> adj[], vector<bool> &vis, vector<bool> &recStack){
    //     vis[course]=1;
    //     recStack[course]=1;
    //     for(auto next:adj[course]){
    //         if(!vis[next]){
    //             if(!dfs(next,adj,vis,recStack)) return false; 
    //         }
    //         else if(recStack[next]) return false;
    //     }
    //     recStack[course]=0;
    //     return true;
    // }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Method-1: TopSort(kahn's algorithm)
        vector<int> indegree(numCourses,0);
        vector<int> adj[numCourses];
        for(auto v:prerequisites){
            indegree[v[0]]++;
            adj[v[1]].push_back(v[0]);
        }
        queue<int> q;
        int cnt=numCourses;
        for(int i=0;i<numCourses;i++) if(indegree[i]==0) q.push(i);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            cnt--;
            for(auto v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }
        }
        return cnt==0;
        
        // Method-2: DFS(detect cycle)
        // vector<int>adj[numCourses];
        // for(auto v:prerequisites) adj[v[1]].push_back(v[0]);
        // vector<bool>vis(numCourses,false), recStack(numCourses,false);
        // for(int i=0;i<numCourses;i++){
        //     if(!vis[i] && !dfs(i,adj,vis,recStack)) return false;
        // }
        // return true;
    }
};