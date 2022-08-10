//problem link: https://practice.geeksforgeeks.org/problems/topological-sort/1

class Solution
{
	public:	
	void dfs(int u, vector<int> adj[], vector<bool> &vis, vector<int> &res){
	    vis[u]=1;
	    for(auto v:adj[u]){
	        if(!vis[v]) dfs(v,adj,vis,res);
	    }
	    res.push_back(u);
	}
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // Method-1: BFS (kahn's algorithm)
	    vector<int> res;
	    vector<int> indegree(V,0);
	    for(int i=0;i<V;i++){
	        for(auto x:adj[i]) indegree[x]++;
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++) if(indegree[i]==0) q.push(i);
	    while(!q.empty()){
	        int u=q.front();
	        q.pop();
	        res.push_back(u);
	        for(auto v:adj[u]){
	            indegree[v]--;
	            if(indegree[v]==0) q.push(v);
	        }
	    }
	    return res;
	    
	   // Method-2: DFS
	   // vector<int> res;
	   // vector<bool> vis(V,0);
	   // for(int i=0;i<V;i++){
	   //     if(!vis[i]) dfs(i,adj,vis,res);
	   // }
	   // reverse(res.begin(),res.end());
	   // return res;
	}
};