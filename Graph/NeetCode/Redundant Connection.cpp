//problem link: https://leetcode.com/problems/redundant-connection/

class Solution {
public:    
    int doFind(int x, vector<int> &parent){
        if(x!=parent[x]){
            parent[x]=doFind(parent[x],parent); //path compression technique
        }
        return parent[x];
    }
    
    void doUnion(int x, int y, vector<int> &parent, vector<int> &rank){
        if(rank[x]<rank[y]) parent[x]=y;
        else if(rank[y]<rank[x]) parent[y]=x;
        else{
            parent[x]=y;
            rank[y]++;
        }
    }    
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> res;
        vector<int> parent(n+1), rank(n+1,0);
        for(int i=1;i<=n;i++) parent[i]=i;
        for(auto &v:edges){
            int x=doFind(v[0],parent), y=doFind(v[1],parent);
            if(x==y){
                res=v;
                break;
            }
            else doUnion(x,y,parent,rank);
        }
        return res;
    }
};