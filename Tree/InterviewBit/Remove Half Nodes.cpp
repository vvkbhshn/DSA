//problem link: https://www.interviewbit.com/problems/remove-half-nodes/

TreeNode* Solution::solve(TreeNode* A) {
    //postorder traversal
    if(A==NULL) return NULL;    
    if(A->left==NULL && A->right==NULL) return A;
    else if(A->left==NULL) return solve(A->right);
    else if(A->right==NULL) return solve(A->left);
    A->left=solve(A->left);
    A->right=solve(A->right);
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