//problem link: https://www.interviewbit.com/problems/least-common-ancestor/
 
bool findTreeNode(TreeNode *A, int B){
    if(A==NULL) return false;
    return A->val==B || findTreeNode(A->left,B) || findTreeNode(A->right,B);
} 
 
TreeNode* check(TreeNode* A, int B, int C){
    if(A==NULL) return NULL;
    if(A->val==B || A->val==C) return A;
    TreeNode* lca1=check(A->left,B,C);
    TreeNode* lca2=check(A->right,B,C);
    if(lca1!=NULL && lca2!=NULL) return A;
    if(lca1!=NULL) return lca1;
    else return lca2;
} 
 
int Solution::lca(TreeNode* A, int B, int C) {
    if(!findTreeNode(A,B) || !findTreeNode(A,C)) return -1;
    TreeNode* res=check(A,B,C);
    return (res!=NULL)?res->val:-1;
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