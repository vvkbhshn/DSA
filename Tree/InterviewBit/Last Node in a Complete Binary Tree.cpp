//problem link: https://www.interviewbit.com/problems/last-node-in-a-complete-binary-tree/
 
int getHeight(TreeNode* A){
    int cnt=0;
    while(A!=NULL){
        A=A->left;
        cnt++;
    }
    return cnt;
} 
 
int Solution::lastNode(TreeNode* A) {
    int res;
    while(A!=NULL){
        res=A->val;
        int left=getHeight(A->left);
        int right=getHeight(A->right);
        if(left==right) A=A->right;
        else A=A->left;
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