//problem link: https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/
 
int mod=1003; 
 
void solve(TreeNode* A, int currSum, int &res){
    if(A==NULL) return;
    if(A->left==NULL && A->right==NULL){
        res=(res+currSum)%mod;
        return;
    }
    if(A->left) solve(A->left,(currSum*10+A->left->val)%mod,res);
    if(A->right) solve(A->right,(currSum*10+A->right->val)%mod,res);
} 
 
int Solution::sumNumbers(TreeNode* A) {
    if(A==NULL) return 0;
    int res=0;
    solve(A,(A->val)%mod,res);
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