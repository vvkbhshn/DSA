//problem link: https://leetcode.com/problems/recover-binary-search-tree/

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
    TreeNode* first=NULL;
    TreeNode* second=NULL;
    TreeNode* prev=NULL;
public:    
    void traverse(TreeNode* root){
        //Inorder Traversal
        if(root==NULL) return;
        traverse(root->left);
        if(prev && root->val<=prev->val){
            if(first==NULL) first=prev;
            second=root;
        }
        prev=root;
        traverse(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        if(root==NULL) return;
        traverse(root);
        if(first && second) swap(first->val,second->val);
    }
};