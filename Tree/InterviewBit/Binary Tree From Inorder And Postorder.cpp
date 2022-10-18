//problem link: https://www.interviewbit.com/problems/binary-tree-from-inorder-and-postorder/
 
TreeNode* solve(vector<int> &inorder, vector<int> &postorder, unordered_map<int,int> &mp, int &index, int lo, int hi){
    if(index<0 || lo>hi) return NULL;   
    TreeNode* root=new TreeNode(postorder[index]);
    int inorderIndex=mp[postorder[index]];
    index--;
    root->right=solve(inorder,postorder,mp,index,inorderIndex+1,hi);
    root->left=solve(inorder,postorder,mp,index,lo,inorderIndex-1);
    return root;
}
 
 
TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder) {
    if(inorder.empty()) return NULL;
    int n=inorder.size();
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++) mp[inorder[i]]=i;
    int index=n-1;
    return solve(inorder,postorder,mp,index,0,n-1);
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