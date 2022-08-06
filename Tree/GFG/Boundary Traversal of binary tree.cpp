//problem link: https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

class Solution {
public:
    void inorder(Node *root, vector<int> &res){
        if(root==NULL) return;
        inorder(root->left,res);
        if(root->left==NULL && root->right==NULL) res.push_back(root->data);
        inorder(root->right,res);
    }
    
    void leftTraversal(Node *root, vector<int> &res){
        if(root==NULL || (root->left==NULL && root->right==NULL)) return;
        res.push_back(root->data);
        if(root->left) leftTraversal(root->left,res);
        else leftTraversal(root->right,res);
    }
    
    void rightTraversal(Node *root, vector<int> &res){
        if(root==NULL || (root->left==NULL && root->right==NULL)) return;
        if(root->right) rightTraversal(root->right,res);
        else rightTraversal(root->left,res);
        res.push_back(root->data);
    }

    vector <int> boundary(Node *root)
    {
        vector<int> res;
        if(root==NULL) return res;
        if(root->left==NULL && root->right==NULL) return {root->data};
        res.push_back(root->data);
        leftTraversal(root->left,res);
        inorder(root,res);
        rightTraversal(root->right,res);
        return res;
    }
};