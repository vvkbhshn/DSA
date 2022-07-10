//problem link: https://leetcode.com/problems/binary-tree-inorder-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    
    void traverse(TreeNode* root, vector<int> &res){
        if(root==NULL) return;
        traverse(root->left,res);
        res.push_back(root->val);
        traverse(root->right,res);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        
        // Method-1: recursive inorder traversal
        traverse(root,res);
        return res;
        
        // Method-2: iterative inorder traversal (using STACK)
        // stack<TreeNode*> s;
        // TreeNode* curr=root;
        // while(!s.empty() || curr!=NULL){
        //     while(curr!=NULL){
        //         s.push(curr);
        //         curr=curr->left;
        //     }
        //     curr=s.top();
        //     s.pop();
        //     res.push_back(curr->val);
        //     curr=curr->right;
        // }
        // return res;
    }
};
