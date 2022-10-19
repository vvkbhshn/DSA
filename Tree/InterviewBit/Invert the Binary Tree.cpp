//problem link: https://www.interviewbit.com/problems/invert-the-binary-tree/

TreeNode* Solution::invertTree(TreeNode* A) {
    if(A==NULL) return NULL;
    A->left=invertTree(A->left);
    A->right=invertTree(A->right);
    swap(A->left,A->right);
    return A;
}

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */