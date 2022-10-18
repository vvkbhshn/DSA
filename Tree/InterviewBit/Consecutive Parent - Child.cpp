//problem link: https://www.interviewbit.com/problems/consecutive-parent-child/

int Solution::consecutiveNodes(TreeNode* A) {
    if(A==NULL) return 0;
    int res=0;
    if(A->left!=NULL){
        if(abs(A->val-A->left->val)==1) res++;
        res+=consecutiveNodes(A->left);
    }
    if(A->right!=NULL){
        if(abs(A->val-A->right->val)==1) res++;
        res+=consecutiveNodes(A->right);
    }
    return res;
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