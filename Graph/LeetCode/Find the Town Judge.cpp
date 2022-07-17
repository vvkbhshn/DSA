//problem link: https://leetcode.com/problems/find-the-town-judge/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {    
        // Method-1:    
        vector<int> count(n+1,0);
        for(auto x:trust){
            count[x[0]]--; //outdegree
            count[x[1]]++; //indegree
        }
        for(int i=1;i<=n;i++){
            //the town judge has (n-1) indegree and 0 outdegree indegree-outdegree=(n-1) 
            //since the max indegree can be (n-1), outdegree will automatically be 0 for indegree-outdegree to be 0
            if(count[i]==n-1) return i;
        }
        return -1;
        
        // Method-2:
        // vector<int> adj[1001];
        // vector<int> indegree(n+1,0);
        // for(auto edge:trust){
        //     adj[edge[0]].push_back(edge[1]);
        //     indegree[edge[1]]++;
        // }
        // for(int i=1;i<=n;i++){
        //     if(indegree[i]==n-1 && adj[i].empty()) return i; 
        // }
        // return -1;
    }
};