//problem link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:    
    vector<int> adj[501];
    bool vis[501];
    
    void traverse(TreeNode* root){
        if(root==NULL) return;
        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            traverse(root->left);
        }
        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            traverse(root->right);
        }
    }
    
    void dfs(int root, vector<int> &res, int k){
        vis[root]=true;
        if(k==0){
            res.push_back(root);
            return;
        }
        for(auto node:adj[root]){
            if(!vis[node]) dfs(node,res,k-1);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        if(root==NULL) return res;
        memset(vis,false,sizeof(vis));
        traverse(root);
        dfs(target->val,res,k);
        return res;
    }
};