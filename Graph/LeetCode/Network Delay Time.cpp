//problem link: https://leetcode.com/problems/network-delay-time/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //Dijkstra's shortest path algorithm
        vector<pair<int,int>> adj[101];
        for(auto x:times) adj[x[0]].push_back({x[1],x[2]});
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,k});
        while(!q.empty()){
            auto p=q.top();
            int u=p.second;
            q.pop();
            for(auto x:adj[u]){
                int v=x.first, weight=x.second;
                if(dist[u]!=INT_MAX && dist[v]>dist[u]+weight){
                    dist[v]=dist[u]+weight;
                    q.push({dist[v],v});
                }
            }
        }
        int res=-1;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
            res=max(res,dist[i]);
        }
        return res;
    }
};