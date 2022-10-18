//problem link: https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/

TreeNode* solve(vector<int> &preorder, vector<int> &inorder, unordered_map<int,int> &mp, int &index, int lo, int hi){
    if(index==preorder.size() || lo>hi) return NULL;    
    TreeNode* root=new TreeNode(preorder[index]);
    int inorderIndex=mp[preorder[index]];
    index++;
    root->left=solve(preorder,inorder,mp,index,lo,inorderIndex-1);
    root->right=solve(preorder,inorder,mp,index,inorderIndex+1,hi);
    return root;
}
 
TreeNode* Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {
    if(preorder.empty()) return NULL;
    unordered_map<int,int> mp;
    for(int i=0;i<inorder.size();i++) mp[inorder[i]]=i;
    int index=0;
    return solve(preorder, inorder, mp, index, 0, preorder.size()-1);
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