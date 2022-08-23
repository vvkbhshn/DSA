//problem link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

class Solution {
public:    
    void inorder(TreeNode *root, int &k, int &res){
        if(root==NULL || k<0) return;
        inorder(root->left,k,res);
        k--;
        if(k==0){
            res=root->val;
            return;
        }
        inorder(root->right,k,res);
    }   
    
    int kthSmallest(TreeNode* root, int k) {
        int res=-1;
        inorder(root,k,res);
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