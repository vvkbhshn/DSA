//problem link: https://leetcode.com/problems/evaluate-division/

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {        
        int n=equations.size();
        unordered_map<string, vector<pair<string,double>>> adj;
        unordered_set<string> vis;
        for(int i=0;i<n;i++){
            adj[equations[i][0]].push_back({equations[i][1],values[i]});
            adj[equations[i][1]].push_back({equations[i][0],1.0/values[i]});
        }
        vector<double> res;
        for(auto x:queries){
            string a=x[0],b=x[1];
            if(adj.find(a)==adj.end() || adj.find(b)==adj.end()){
                res.push_back(-1.0);
                continue;
            }
            double temp=-1.0;
            queue<pair<string,double>> q;
            q.push({a,1.0});
            vis.insert(a);
            while(!q.empty()){
                auto p=q.front(); q.pop();
                if(p.first==b){
                    temp=p.second;
                    break;
                }
                for(auto next:adj[p.first]){
                    if(vis.find(next.first)==vis.end()){
                        q.push({next.first,p.second*next.second});
                        vis.insert(next.first);  
                    }
                }
            }
            res.push_back(temp);
            vis.clear();
        }
        return res;
    }
};