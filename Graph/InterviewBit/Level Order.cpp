//problem link: https://www.interviewbit.com/problems/level-order/

vector<vector<int>> Solution::levelOrder(TreeNode* A) {
    vector<vector<int>> res;
    if(A==NULL) return res;
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()){
        int n=q.size();
        vector<int> v;
        while(n--){
            TreeNode* curr=q.front();
            q.pop();
            v.push_back(curr->val);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        res.push_back(v);
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