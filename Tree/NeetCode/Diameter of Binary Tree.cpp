//problem link: https://leetcode.com/problems/diameter-of-binary-tree/

class Solution {
public:    
    int height(TreeNode *root, int &res){
        if(root==NULL) return 0;
        int leftHeight=height(root->left,res);
        int rightHeight=height(root->right,res);
        res=max(res,leftHeight+rightHeight);
        return 1+max(leftHeight,rightHeight);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int res=0;
        height(root,res);
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