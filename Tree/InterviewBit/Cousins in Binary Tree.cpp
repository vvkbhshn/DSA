//problem link: https://www.interviewbit.com/problems/cousins-in-binary-tree/

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> res;
    if(A==NULL || A->val==B) return res;    
    queue<TreeNode*> q;
    q.push(A);
    bool found=false;
    while(!q.empty() && !found){
        int n=q.size();
        for(int i=0;i<n;i++){
            TreeNode* curr=q.front();
            q.pop();
            if(!found && ((curr->left && curr->left->val==B) || (curr->right && curr->right->val==B))) found=true;
            else{
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
    }
    while(!q.empty()){
        res.push_back(q.front()->val);
        q.pop();
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