//problem link: https://www.interviewbit.com/problems/reverse-level-order/

vector<int> Solution::solve(TreeNode* A) {
    vector<int> res;
    if(A==NULL) return res;
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            TreeNode* curr=q.front();
            q.pop();
            res.push_back(curr->val);
            if(curr->right) q.push(curr->right);
            if(curr->left) q.push(curr->left);
        }
    }
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