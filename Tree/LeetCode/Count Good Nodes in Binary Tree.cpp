//problem link: https://leetcode.com/problems/count-good-nodes-in-binary-tree/

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
    
    void countNodes(TreeNode* root, int maxVal, int &res){
        if(root==NULL) return;
        if(root->val>=maxVal) res++;
        maxVal=max(maxVal,root->val);
        countNodes(root->left,maxVal,res);
        countNodes(root->right,maxVal,res);
    }
    
    int goodNodes(TreeNode* root) {
        int res=0;
        countNodes(root,INT_MIN,res);
        return res;
    }
};