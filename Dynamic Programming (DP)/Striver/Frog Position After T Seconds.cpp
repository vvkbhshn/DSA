//problem link: https://leetcode.com/problems/frog-position-after-t-seconds/

class Solution {
public:    
    double solve(int root, int &target, double prob, vector<unordered_set<int>> &adj, int t){
        if(t<0) return 0.0;  
        if(root==target && (t==0 || adj[root].empty())) return prob;
        int n=adj[root].size();
        for(auto child:adj[root]){
            adj[child].erase(root);
            double res=solve(child,target,prob/n,adj,t-1);
            if(res!=0.0) return res;
        }   
        return 0.0;
    }    
    
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if(n==1) return 1.0;
        vector<unordered_set<int>> adj(n+1);
        for(auto &v:edges){
            adj[v[0]].insert(v[1]);
            adj[v[1]].insert(v[0]);
        }
        return solve(1,target,1.0,adj,t);
    }
};