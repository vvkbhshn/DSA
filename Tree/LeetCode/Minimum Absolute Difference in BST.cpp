//problem link: https://leetcode.com/problems/minimum-absolute-difference-in-bst/

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
    
    void inorderTraverse(TreeNode* root, int &minDiff, int &val){
        //inorder traversal of a BST is always in ascending order
        if(root->left!=NULL) inorderTraverse(root->left,minDiff,val);
        if(val>=0) minDiff=min(minDiff,root->val-val);
        val=root->val;
        if(root->right!=NULL) inorderTraverse(root->right,minDiff,val);
    }
    
    int getMinimumDifference(TreeNode* root) {
        int minDiff=INT_MAX, val=-1;
        inorderTraverse(root,minDiff,val);
        return minDiff;
    }
};