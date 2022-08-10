//problem link: https://leetcode.com/problems/clone-graph/

class Solution {
public:
    unordered_map<Node*,Node*> mp;
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        if(mp.find(node)!=mp.end()) return mp[node];
        Node *root=new Node(node->val);
        mp[node]=root;
        for(auto next: node->neighbors){
            root->neighbors.push_back(cloneGraph(next));
        }
        return root;
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