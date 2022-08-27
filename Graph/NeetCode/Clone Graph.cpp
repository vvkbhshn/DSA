//problem link: https://leetcode.com/problems/clone-graph/

class Solution {
private:
    unordered_map<Node*,Node*> mp;
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        if(mp.find(node)==mp.end()){
            mp[node]=new Node(node->val);
            for(auto neighbor:node->neighbors){
                mp[node]->neighbors.push_back(cloneGraph(neighbor));
            } 
        }               
        return mp[node];
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/