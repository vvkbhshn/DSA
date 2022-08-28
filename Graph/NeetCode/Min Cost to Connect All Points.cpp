//problem link: https://leetcode.com/problems/min-cost-to-connect-all-points/

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        int res=0;
        vector<bool> vis(n,0);
        vector<int> dist(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        dist[0]=0;
        int nodes=0;
        while(!pq.empty() && nodes<n){
            auto p=pq.top();
            pq.pop();
            if(vis[p.second]) continue;            
            res+=p.first;
            vis[p.second]=1;
            int x=points[p.second][0], y=points[p.second][1];
            for(int i=0;i<n;i++){
                int cost=abs(x-points[i][0])+abs(y-points[i][1]);
                if(!vis[i] && dist[i]>cost){                    
                    pq.push({cost,i});
                    dist[i]=cost;
                }
            }
            nodes++;
        }
        return res;
    }
};