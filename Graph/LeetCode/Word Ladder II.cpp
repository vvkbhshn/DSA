//problem link: https://leetcode.com/problems/word-ladder-ii/

class Solution {
public:
    vector<vector<string>> res;
    unordered_map<string,vector<string>> parent;
    unordered_map<string,int> dist;
   
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList){       
        for(auto &node: wordList){
            parent[node]={};
            dist[node]=INT_MAX;
        }
        parent[beginWord]={"root"};
        dist[beginWord]=1;
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            auto parentNode=q.front();
            q.pop();
            for(int i=0;i<parentNode.length();i++){
                string childNode=parentNode;
                for(char c='a';c<='z'; c++){
                    childNode[i]=c;
                    if(dist.find(childNode)!=dist.end()){
                        if(dist[childNode]>1+dist[parentNode]){
                            dist[childNode]=1+dist[parentNode];
                            parent[childNode].clear();
                            parent[childNode].push_back(parentNode);
                            q.push(childNode);
                        }
                        else if(dist[childNode]==1+dist[parentNode])
                            parent[childNode].push_back(parentNode);
                    }
                }
            }
        }
        vector<string> path;
        pathFinder(endWord,path);
        for(auto &v:res) reverse(v.begin(),v.end());
        return res;
    }
    
    void pathFinder(string node, vector<string> &path){
        if(node=="root"){
            res.push_back(path);
            return;
        }
        for(auto next:parent[node]){
            path.push_back(node);
            pathFinder(next,path);
            path.pop_back();
        }
    }
};