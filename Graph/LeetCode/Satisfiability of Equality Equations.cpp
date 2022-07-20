//problem link: https://leetcode.com/problems/satisfiability-of-equality-equations/

class Solution {
public:    
    int doFind(int x, vector<int> &parent){
        if(parent[x]==x) return x;
        parent[x]=doFind(parent[x],parent);        
        return parent[x];
    }
        
    bool equationsPossible(vector<string>& equations) {        
        vector<int> parent(26);
        for(int i=0;i<26;i++) parent[i]=i;
        
        for(auto p:equations){
            if(p[1]=='='){
                parent[doFind(p[0]-'a',parent)]=doFind(p[3]-'a',parent);
            } 
        }
        for(auto p:equations){
            if(p[1]=='!' && doFind(p[0]-'a',parent)==doFind(p[3]-'a',parent)){
                return false;
            }
        }
        return true;
    }
};