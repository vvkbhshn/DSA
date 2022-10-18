//problem link: https://www.interviewbit.com/problems/merge-two-binary-tree/

TreeNode* Solution::solve(TreeNode* A, TreeNode* B) {
    // Method-1:
    TreeNode* root=new TreeNode(0);
    if(A==NULL && B==NULL) return NULL;
    else if(A==NULL){
        root->val=B->val;
        root->left=solve(A,B->left);
        root->right=solve(A,B->right);
    }
    else if(B==NULL){
        root->val=A->val;
        root->left=solve(A->left,B);
        root->right=solve(A->right,B);
    }
    else{
        root->val=A->val+B->val;
        root->left=solve(A->left,B->left);
        root->right=solve(A->right,B->right);
    }
    return root;
    
    // Method-2:
    // if(A==NULL) return B;
    // if(B==NULL) return A;
    // A->val+=B->val;
    // A->left=solve(A->left,B->left);
    // A->right=solve(A->right,B->right);
    // delete B;
    // return A;
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