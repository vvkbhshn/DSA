//problem link: https://www.interviewbit.com/problems/inorder-traversal-of-cartesian-tree/
 
TreeNode* solve(vector<int> &A, int lo, int hi){
    if(lo>hi) return NULL;
    int index, maxVal=0;
    for(int i=lo;i<=hi;i++){
        if(A[i]>maxVal){
            maxVal=A[i];
            index=i;
        }
    }
    TreeNode* root=new TreeNode(A[index]);
    root->left=solve(A,lo,index-1);
    root->right=solve(A,index+1,hi);
    return root;
}  
 
TreeNode* Solution::buildTree(vector<int> &A) {
    if(A.empty()) return NULL;
    return solve(A,0,A.size()-1);
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