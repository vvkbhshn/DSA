//problem link: https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:    
    void dfs(int node, int n, vector<vector<int>> &graph, vector<int> &path, vector<vector<int>> &res){        
        if(node==n-1){
            res.push_back(path);
            return;
        }
        for(auto v: graph[node]){
            path.push_back(v);
            dfs(v,n,graph,path,res);
            path.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path={0};
        int n=graph.size();
        dfs(0,n,graph,path,res);
        return res;
    }
};