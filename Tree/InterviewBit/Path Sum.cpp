// problem link: https://www.interviewbit.com/problems/path-sum/
 
bool solve(TreeNode* A, int currSum){
    if(A==NULL) return false;
    currSum-=A->val;
    if(A->left==NULL && A->right==NULL){
        if(currSum==0) return true;
        else return false;
    }
    return solve(A->left,currSum) || solve(A->right,currSum);
} 
 
int Solution::hasPathSum(TreeNode* A, int B) {
    if(solve(A,B)) return 1;
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