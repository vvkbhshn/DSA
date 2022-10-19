//problem link: https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/
 
void solve(TreeNode* A, int B, vector<int> &curr, vector<vector<int>> &res){
    if(A==NULL) return; 
    B-=A->val;   
    if(A->left==NULL && A->right==NULL){
        if(B==0) res.push_back(curr);
        return;
    }
    if(A->left!=NULL){
        curr.push_back(A->left->val);
        solve(A->left,B,curr,res);
        curr.pop_back();
    }
    if(A->right!=NULL){
        curr.push_back(A->right->val);
        solve(A->right,B,curr,res);
        curr.pop_back();
    }    
} 
 
vector<vector<int>> Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int>> res;
    if(A==NULL) return res;
    vector<int> curr={A->val};
    solve(A,B,curr,res);
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