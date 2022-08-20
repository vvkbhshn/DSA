//problem link: https://leetcode.com/problems/balanced-binary-tree/

class Solution {
public:    
    bool dfs(TreeNode *root, int &height){
        if(root==NULL){
            height=0;
            return true;
        }
        int left=0, right=0;
        if(!dfs(root->left,left) || !dfs(root->right,right)) return false;
        if(abs(left-right)>1) return false;
        height=1+max(left,right);
        return true;
    }
    
    bool isBalanced(TreeNode* root) {
        int height=0;
        return dfs(root,height);
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