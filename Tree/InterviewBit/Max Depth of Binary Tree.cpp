//problem link: https://www.interviewbit.com/problems/max-depth-of-binary-tree/

int Solution::maxDepth(TreeNode* A) {
    // Method-1: dfs
    if(A==NULL) return 0;
    return 1+max(maxDepth(A->left),maxDepth(A->right));    
    
    // Method-2: bfs
    // if(A==NULL) return 0;
    // int res=0;
    // queue<TreeNode*> q;
    // q.push(A);
    // while(!q.empty()){
    //     int n=q.size();
    //     while(n--){
    //         TreeNode* curr=q.front();
    //         q.pop();
    //         if(curr->left) q.push(curr->left);
    //         if(curr->right) q.push(curr->right);
    //     }
    //     res++;
    // }
    // return res;
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