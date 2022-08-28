//problem link: https://leetcode.com/problems/network-delay-time/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto v:times){
            adj[v[0]].push_back({v[1],v[2]});
        }
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            if(dist[p.second]<p.first) continue;
            int u=p.second;           
            for(auto p:adj[u]){
                int v=p.first, wt=p.second;
                if(dist[v]>dist[u]+wt){
                    dist[v]=dist[u]+wt;
                    pq.push({dist[v],v});
                }
            }
        }
        int res=-1;
        for(int i=1;i<=n;i++) res=max(res,dist[i]);
        if(res==INT_MAX) return -1;
        return res;
    }
};