//problem link: https://www.interviewbit.com/problems/balanced-binary-tree/
 
int getHeight(TreeNode *A){
    if(A==NULL) return 0;
    int leftHeight=getHeight(A->left);
    int rightHeight=getHeight(A->right);
    if(leftHeight==-1 || rightHeight==-1 || abs(leftHeight-rightHeight)>1) return -1;
    return 1+max(leftHeight,rightHeight);
} 
 
int Solution::isBalanced(TreeNode* A) {
    if(getHeight(A)!=-1) return 1;
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