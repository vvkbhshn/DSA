//problem link: https://www.interviewbit.com/problems/kth-smallest-element-in-tree/
 
int inorder(TreeNode* A, int &k){
    if(A==NULL) return -1;
    int left=inorder(A->left,k);
    if(left!=-1) return left;
    k--;
    if(k==0) return A->val;
    int right=inorder(A->right,k);
    if(right!=-1) return right;
} 
 
int Solution::kthsmallest(TreeNode* A, int k) {
    return inorder(A,k);
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