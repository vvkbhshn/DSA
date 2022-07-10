//problem link: https://leetcode.com/problems/validate-binary-search-tree/

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
    
    bool check(TreeNode* root, long minVal, long maxVal){
        if(root==NULL) return true;
        if(root->val<minVal || root->val>maxVal) return false;
        return check(root->left,minVal,(long)root->val-1) && 
               check(root->right,(long)root->val+1,maxVal);
    }
    
    bool inorder(TreeNode* root, TreeNode* &prev){
        //inorder traversal of a BST is always sorted
        if(root==NULL) return true;
        if(!inorder(root->left,prev)) return false;
        if(prev!=NULL && root->val<=prev->val) return false;
        prev=root;
        return inorder(root->right,prev);
    }
    
    bool isValidBST(TreeNode* root) {
        
        // Method-1:
        TreeNode* prev=NULL;
        return inorder(root,prev);
        
        // Method-2: using min max range
        // return check(root,LONG_MIN,LONG_MAX);
    }
};