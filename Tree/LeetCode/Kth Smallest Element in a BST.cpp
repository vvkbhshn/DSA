//problem link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    
    void inorder(TreeNode* root, int k, int &prev, int &res){
        if(root==NULL) return;
        if(prev>k) return;
        inorder(root->left,k,prev,res);
        prev++;
        if(prev==k){
            res=root->val;
            return;
        }        
        inorder(root->right,k,prev,res);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL) return -1;
        int prev=0, res;
        inorder(root,k,prev,res);
        return res;
    }
};