//problem link: https://practice.geeksforgeeks.org/problems/sum-tree/1

class Solution
{
    public:    
    int check(Node *root){
        if(root==NULL) return 0;
        int l=check(root->left);
        int r=check(root->right);
        if(l==-1 || r==-1 || ((root->left || root->right) && root->data!=(l+r))) return -1;
        return root->data+l+r;
    }
    
    bool isSumTree(Node* root)
    {
        if(check(root)==-1) return false;
        return true;
    }
};