//problem link: https://leetcode.com/problems/number-of-provinces/

class Solution {
public:    
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool> &vis, int n){
        vis[node]=true;
        for(int i=0;i<n;i++){
            if(!vis[i] && isConnected[node][i]==1) dfs(i,isConnected,vis,n);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> vis(n,false);
        int cnt=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                cnt++;
                dfs(i,isConnected,vis,n);
            }
        }
        return cnt;
    }
};