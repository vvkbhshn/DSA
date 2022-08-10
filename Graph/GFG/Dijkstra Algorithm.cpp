//problem link: https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

class Solution
{
	public:
	class myCmp{
        public:
        bool operator()(pair<int,int> &a, pair<int,int> &b){
            return a.first>b.first;
        }
    };
	
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V,INT_MAX);
        dist[S]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,myCmp> q;
        q.push({0,S});
        while(!q.empty()){
            auto p=q.top();
            q.pop();
            int u=p.second;
            for(auto v:adj[u]){
                if(dist[v[0]]>dist[u]+v[1]){
                    dist[v[0]]=dist[u]+v[1];
                    q.push({dist[v[0]],v[0]});
                }
            }
        }
        return dist;
    }
};