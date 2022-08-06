//problem link: https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

class Solution {
  public:
    
    int height(Node *root, int &res){
        if(root==NULL) return 0;
        int l=height(root->left,res);
        int r=height(root->right,res);
        res=max(res,1+l+r);
        return 1+max(l,r);
    }
    
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        int res=0;
        height(root,res);
        return res;
    }
};