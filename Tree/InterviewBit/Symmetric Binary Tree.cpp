//problem link: https://www.interviewbit.com/problems/symmetric-binary-tree/

bool check(TreeNode* A, TreeNode* B){
    if(A==NULL || B==NULL) return A==B;
    return A->val==B->val && check(A->left,B->right) && check(A->right,B->left);
} 
 
int Solution::isSymmetric(TreeNode* A) {
    if(A==NULL || check(A->left,A->right)) return 1;
    return 0;
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