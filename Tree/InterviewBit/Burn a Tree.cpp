//problem link: https://www.interviewbit.com/problems/burn-a-tree/
 
int getHeight(TreeNode* A, int B, unordered_map<int,int> &mp, int &res, int level){
    if(A==NULL) return 0;
    int left=getHeight(A->left,B,mp,res,level+1);
    int right=getHeight(A->right,B,mp,res,level+1);
    mp[A->val]=level;
    if(left==-1){
        res=max(res,mp[B]-level+right);
        return -1;
    } 
    if(right==-1){
        res=max(res,mp[B]-level+left);
        return -1;
    }
    if(A->val==B) return -1;
    return 1+max(left,right);
}
 
int Solution::solve(TreeNode* A, int B) {
    if(A==NULL || (A->left==NULL && A->right==NULL)) return 0;
    unordered_map<int,int> mp;
    int res=0;
    getHeight(A,B,mp,res,0);
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