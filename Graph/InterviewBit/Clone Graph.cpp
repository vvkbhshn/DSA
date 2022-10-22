//problem link: https://www.interviewbit.com/problems/clone-graph/
 
unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> mp; 
 
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    if(node==NULL) return NULL;
    if(mp.find(node)!=mp.end()) return mp[node];
    mp[node]=new UndirectedGraphNode(node->label);
    for(auto &neighbor: node->neighbors){
        mp[node]->neighbors.push_back(cloneGraph(neighbor));
    }
    return mp[node];
}

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */