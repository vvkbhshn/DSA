//problem link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

class Solution {
public:
    unordered_map<int,int> parent, rank;
    int connectedComponents;
    
    int findParent(int x){
        if(parent.find(x)==parent.end()){
            parent[x]=x;
            connectedComponents++;
        }
        if(parent[x]!=x) parent[x]=findParent(parent[x]);
        return parent[x];
    }
    
    void findUnion(int x, int y){
        if(rank.find(x)==rank.end()) rank[x]=0;
        if(rank.find(y)==rank.end()) rank[y]=0;
        if(rank[x]<rank[y]) parent[x]=y;
        else if(rank[y]<rank[x]) parent[y]=x;
        else{
            parent[y]=x;
            rank[x]++;
        }
        connectedComponents--;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        connectedComponents=0;
        for(auto v:stones){
            int x=findParent(v[0]), y=findParent(v[1]+10001);
            if(x!=y) findUnion(x,y);
        }
        return n-connectedComponents;
    }
};