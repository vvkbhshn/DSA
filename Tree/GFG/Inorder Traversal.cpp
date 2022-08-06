//problem link: https://practice.geeksforgeeks.org/problems/inorder-traversal/1

class Solution {
  public:  
    void traverse(Node *root, vector<int> &res){
        if(root==NULL) return;
        traverse(root->left,res);
        res.push_back(root->data);
        traverse(root->right,res);
    }  
  
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        vector<int> res;
        
        //Method-1: recursive
        // traverse(root,res);
        
        //Method-2: iterative
        stack<Node*> s;
        Node *curr=root;
        while(!s.empty() || curr!=NULL){
            while(curr!=NULL){
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();
            s.pop();
            res.push_back(curr->data);
            curr=curr->right;
        }
        return res;
    }
};