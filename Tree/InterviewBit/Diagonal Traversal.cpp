//problem link: https://www.interviewbit.com/problems/diagonal-traversal/

vector<int> Solution::solve(TreeNode* A){
    vector<int> res;
    if(A==NULL) return res;
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            TreeNode* curr=q.front();
            q.pop();
            while(curr!=NULL){
                res.push_back(curr->val);
                if(curr->left!=NULL) q.push(curr->left);
                curr=curr->right;
            }
        }
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