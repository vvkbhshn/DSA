//problem link: https://www.interviewbit.com/problems/covered-uncovered-nodes/

long Solution::coveredNodes(TreeNode* A) {
    if(A==NULL) return 0;
    long uncoveredSum=0, coveredSum=0;
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            TreeNode* curr=q.front();
            q.pop();
            if(i==0 || i==n-1) uncoveredSum+=curr->val;
            else coveredSum+=curr->val;
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    return abs(uncoveredSum-coveredSum);
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