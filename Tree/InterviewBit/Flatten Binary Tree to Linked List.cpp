//problem link: https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/
 
TreeNode* Solution::flatten(TreeNode* A) {
    if(A==NULL) return NULL;
    TreeNode* curr=A;
    while(curr!=NULL){
        TreeNode* next=curr->right;
        if(curr->left){
            TreeNode* temp=curr->left;
            while(temp->right!=NULL) temp=temp->right;
            temp->right=curr->right;
            curr->right=curr->left;
            curr->left=NULL;
        }
        curr=curr->right;
    }
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