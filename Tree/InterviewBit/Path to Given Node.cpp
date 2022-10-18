//problem link: https://www.interviewbit.com/problems/path-to-given-node/

bool postorder(TreeNode* A, int B, vector<int> &res){
    if(A==NULL) return false;
    bool ret=false;
    if(postorder(A->left,B,res) || postorder(A->right,B,res) || A->val==B) ret=true;
    if(ret) res.push_back(A->val);
    return ret;
} 
 
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> res;
    postorder(A,B,res);
    reverse(res.begin(),res.end());
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