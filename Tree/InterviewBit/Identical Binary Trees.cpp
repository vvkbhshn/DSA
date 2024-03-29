//problem link: https://www.interviewbit.com/problems/identical-binary-trees/

int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if(A==NULL || B==NULL) return A==B;
    return A->val==B->val && isSameTree(A->left,B->left) && isSameTree(A->right,B->right);
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