//problem link: https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/
 
TreeNode* solve(const vector<int> &A, int lo, int hi){
    if(lo>hi) return NULL;
    int mid=lo+(hi-lo)/2;
    TreeNode* root=new TreeNode(A[mid]);
    root->left=solve(A,lo,mid-1);
    root->right=solve(A,mid+1,hi);
    return root;
} 
 
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
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