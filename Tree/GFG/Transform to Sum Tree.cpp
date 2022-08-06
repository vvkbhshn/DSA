//problem link: https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1

class Solution {
  public:
  
    int solve(Node *root){
        if(root==NULL) return 0;
        int l=solve(root->left);
        int r=solve(root->right);
        int sum=root->data+l+r;
        root->data=l+r;
        return sum;
    }
  
    void toSumTree(Node *node)
    {
        solve(node);
    }
};