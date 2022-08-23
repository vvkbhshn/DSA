//problem link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

class Solution {   
public:    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int &index, int l, int r){
        if(l>r) return NULL;
        TreeNode *root=new TreeNode(preorder[index]);
        int currIndex=0;
        for(int i=l;i<=r;i++){
            if(inorder[i]==preorder[index]){
                currIndex=i;
                break;
            }
        }
        index++;
        root->left=build(preorder,inorder,index,l,currIndex-1);
        root->right=build(preorder,inorder,index,currIndex+1,r);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0;
        return build(preorder,inorder,index,0,preorder.size()-1);        
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */