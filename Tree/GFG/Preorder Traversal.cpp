//problem link: https://practice.geeksforgeeks.org/problems/preorder-traversal/1

void traverse(Node* root, vector<int> &res){
    if(root==NULL) return;
    res.push_back(root->data);
    traverse(root->left,res);
    traverse(root->right,res);
}

//Function to return a list containing the preorder traversal of the tree.
vector <int> preorder(Node* root)
{
    vector<int> res;
    
    //Method-1: Recursive
    //traverse(root,res);
    
    //Method-2: Iterative
    stack<Node*> s;
    Node *curr=root;
    while(!s.empty() || curr!=NULL){
        while(curr!=NULL){
            res.push_back(curr->data);
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        curr=curr->right;
    }    
    return res;
}