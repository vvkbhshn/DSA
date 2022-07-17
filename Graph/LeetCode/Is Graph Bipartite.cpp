//problem link: https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,0); // 0-> uncolored, 1-> color A, 2-> color B
        for(int i=0;i<n;i++){
            if(color[i]) continue;
            queue<int> q;
            q.push(i);
            color[i]=1;
            while(!q.empty()){
                int u=q.front(); 
                q.pop();
                for(auto v:graph[u]){
                    if(!color[v]){
                        color[v]=-color[u];
                        q.push(v);
                    }
                    else if(color[v]==color[u]) return false;
                }
            }
        }
        return true;
    }
};