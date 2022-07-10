//problem link: https://leetcode.com/problems/merge-two-binary-trees/

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // in the real world, sharing nodes between the old trees and the new tree can be a problem. If any of the old trees is deleted, it's going to also destruct the shared nodes in the new tree
        // so create a new tree for merging the given trees
        
        if(root1!=NULL && root2!=NULL){
            TreeNode *root=new TreeNode(root1->val+root2->val);
            root->left=mergeTrees(root1->left,root2->left);
            root->right=mergeTrees(root1->right,root2->right);
            return root;
        }
        else return (root1)? root1:root2;
    }
};