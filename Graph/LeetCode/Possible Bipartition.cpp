//problem link: https://leetcode.com/problems/possible-bipartition/

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[2001];
        for(auto x:dislikes){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> color(n+1,0); // 0->unvisited, 1->color A, 2->color B
        for(int i=1;i<=n;i++){
            if(color[i]!=0) continue;
            queue<int> q;
            q.push(i);
            color[i]=1;
            while(!q.empty()){
                int u=q.front();
                q.pop();
                for(auto v:adj[u]){
                    if(color[v]==0){
                        //unvisited
                        color[v]=-color[u];
                        q.push(v);
                    }
                    else if(color[u]==color[v]){
                        //same color on adjacent nodes
                        return false;
                    }
                }
            }
        }
        return true;        
    }
};