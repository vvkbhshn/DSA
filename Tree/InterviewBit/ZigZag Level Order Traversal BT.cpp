//problem link: https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int>> res;
    if(A==NULL) return res;
    queue<TreeNode*> q;
    q.push(A);
    bool rev=false;
    while(!q.empty()){
        int n=q.size();
        vector<int> temp(n);
        int j=0;
        if(rev) j=n-1;
        for(int i=0;i<n;i++){
            TreeNode* curr=q.front();
            q.pop();
            if(rev) temp[j--]=curr->val;
            else temp[j++]=curr->val;
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        res.push_back(temp);
        rev=!rev;
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