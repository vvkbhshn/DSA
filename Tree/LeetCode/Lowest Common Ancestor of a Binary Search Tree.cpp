//problem link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // Method-1: for binary search tree
        if(root->val<p->val && root->val<q->val) 
            return lowestCommonAncestor(root->right,p,q); 
        if(root->val>p->val && root->val>q->val)
            return lowestCommonAncestor(root->left,p,q);
        return root;
        
        // Method-2: for binary tree
        // if(root==NULL) return NULL;
        // if(root==p || root==q) return root;
        // TreeNode* lca1=lowestCommonAncestor(root->left,p,q);
        // TreeNode* lca2=lowestCommonAncestor(root->right,p,q);
        // if(lca1 && lca2) return root;
        // else if(lca1) return lca1;
        // else return lca2;
    }
};
