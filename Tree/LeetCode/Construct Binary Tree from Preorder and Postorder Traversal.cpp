//problem link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

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
private:
    int preIndex=0, postIndex=0;    
public:    
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        // When we meet a node value pre[i] equals to the current post[j], it means we have completed building the subtree of pre[i]. So we should not continue to add child nodes to that subtree. Instead, we should pop that subtree and continues to the path where we can add child nodes.
        TreeNode* root=new TreeNode(pre[preIndex++]);
        if(root->val!=post[postIndex]){
            root->left=constructFromPrePost(pre,post);
        }
        if(root->val!=post[postIndex]){
            root->right=constructFromPrePost(pre,post);
        }
        postIndex++;
        return root;
    }
};