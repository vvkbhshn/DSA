//problem link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<int> numCities(n,0);
        vector<pair<int,int>> adj[101];
        for(auto p:edges){
            adj[p[0]].push_back({p[1],p[2]});
            adj[p[1]].push_back({p[0],p[2]});
        }
        vector<int> dist(n,INT_MAX);
        for(int i=0;i<n;i++){  
            //Dijkstra's shortest path Algorithm
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
            q.push({0,i});
            dist[i]=0;
            while(!q.empty()){
                auto p=q.top();
                q.pop();
                int u=p.second;
                for(auto x:adj[u]){
                    int v=x.first, weight=x.second;
                    if(dist[v]>dist[u]+weight){
                        dist[v]=dist[u]+weight;
                        q.push({dist[v],v});
                    }
                }
            }
            for(int j=0;j<n;j++) if(j!=i && dist[j]<=distanceThreshold) numCities[i]++;
            fill(dist.begin(),dist.end(),INT_MAX);
        }
        int res=-1, flag=INT_MAX;
        for(int i=0;i<n;i++){
            if(flag>=numCities[i]){
                flag=numCities[i];
                res=i;
            }
        }
        return res;
    }
};