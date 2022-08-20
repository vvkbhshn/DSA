//problem link: https://leetcode.com/problems/count-good-nodes-in-binary-tree/

class Solution {
public:    
    void countNodes(TreeNode *root, int &res, int currMax){
        if(root==NULL) return;
        currMax=max(currMax,root->val);
        if(currMax<=root->val) res++;
        countNodes(root->left,res,currMax);
        countNodes(root->right,res,currMax);
    }
    
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int res=0;
        countNodes(root,res,INT_MIN);
        return res;
    }
};

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