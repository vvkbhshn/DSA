//problem link: https://leetcode.com/problems/sum-of-left-leaves/

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
    
    void findSum(TreeNode* root, int &res){
        if(root==NULL) return;
        if(root->left && (root->left->left==NULL && root->left->right==NULL)){
            res+=root->left->val;
        }
        else findSum(root->left,res);
        findSum(root->right,res);
    }
    
    void dfs(TreeNode* root, int &res, bool isLeft){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL && isLeft) res+=root->val;
        else dfs(root->left,res,true);
        dfs(root->right,res,false);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL) return 0;
        int res=0;
        // Method-1:
        dfs(root,res,false);
        // Method-2:
        // findSum(root,res);
        return res;
    }
};