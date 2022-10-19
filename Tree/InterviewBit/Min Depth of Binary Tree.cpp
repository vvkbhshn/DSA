//problem link: https://www.interviewbit.com/problems/min-depth-of-binary-tree/
 
int Solution::minDepth(TreeNode* A) {
    if(A==NULL) return 0;
    if(A->left==NULL && A->right==NULL) return 1;
    int left=minDepth(A->left);
    int right=minDepth(A->right);
    if(A->left==NULL) return 1+right;
    if(A->right==NULL) return 1+left;
    return 1+min(left,right);
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