//problem link: https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1

class Solution
{
    private:
    Node* prev=NULL;
    Node* head=NULL;
    
    public:
    void inorder(Node *root){
        if(root==NULL) return;
        inorder(root->left);
        if(prev!=NULL){
            prev->right=root;
            root->left=prev;
        }
        else head=root;
        prev=root;
        inorder(root->right);
    }    
    
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        inorder(root);
        return head;
    }
};
