//problem link: https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //find the topological sort of the given graph
        //Kahn's toplogical sort algorithm
        vector<int> topSort;
        int indegree[2001]={0};
        vector<int> adj[2001];
        for(auto edge:prerequisites){
            indegree[edge[0]]++;
            adj[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++) if(indegree[i]==0) q.push(i);
        while(!q.empty()){
            int u=q.front();
            topSort.push_back(u);
            q.pop();
            for(auto v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }
        }
        if(topSort.size()!=numCourses) topSort.clear();
        return topSort;
    }
};