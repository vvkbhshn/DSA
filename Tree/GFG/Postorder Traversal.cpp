//problem link: https://practice.geeksforgeeks.org/problems/postorder-traversal/1

void traverse(Node *root, vector<int> &res){
    if(root==NULL) return;
    traverse(root->left,res);
    traverse(root->right,res);
    res.push_back(root->data);
}

//Function to return a list containing the postorder traversal of the tree.
vector <int> postOrder(Node* root)
{
    vector<int> res;
    
    //Method-1: Recursive
    // traverse(root,res);
    
    //Method-2: Iterative
    stack<Node*> s1,s2;
    s1.push(root);
    Node* curr=root;
    while(!s1.empty()){
        curr=s1.top();
        s1.pop();
        s2.push(curr);
        if(curr->left) s1.push(curr->left);
        if(curr->right) s1.push(curr->right);
    }
    while(!s2.empty()){
        res.push_back(s2.top()->data);
        s2.pop();
    }    
    return res;
}