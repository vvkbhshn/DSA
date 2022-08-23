//problem link: https://leetcode.com/problems/binary-tree-maximum-path-sum/

class Solution {
public:    
    int findMaxPathSum(TreeNode *root, int &maxSum){
        if(root==NULL) return 0;
        int left=max(findMaxPathSum(root->left,maxSum),0);
        int right=max(findMaxPathSum(root->right,maxSum),0);
        maxSum=max(maxSum,root->val+left+right);
        return root->val+max(left,right);
    }    
    
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        findMaxPathSum(root,maxSum);
        return maxSum;
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