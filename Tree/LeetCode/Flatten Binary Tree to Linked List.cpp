//problem link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
private:
    TreeNode* prev=NULL;
public:   
    
    void solve(TreeNode* root){
        if(root==NULL) return;
        TreeNode* leftNode=root->left;
        TreeNode* rightNode=root->right;
        if(prev) prev->right=root;
        prev=root;
        solve(leftNode);
        solve(rightNode);
        root->left=NULL;
    }
    
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        
        // Method-1: using postOrder traversal
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root;
        
        // Method-2:
        // solve(root);
        
        // Method-3:
        // TreeNode* curr=root;
        // while(curr){
        //     if(curr->left){
        //         TreeNode* prev=curr->left;
        //         while(prev->right) prev=prev->right;
        //         prev->right=curr->right;
        //         curr->right=curr->left;
        //         curr->left=NULL;
        //     }
        //     curr=curr->right;
        // }
    }
};