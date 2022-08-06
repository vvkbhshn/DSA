//problem link: https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1

vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int> res;
    if(root==NULL) return res;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *curr=q.front();
        q.pop();
        res.push_back(curr->data);
        if(curr->right) q.push(curr->right);
        if(curr->left) q.push(curr->left);
    }
    reverse(res.begin(), res.end());
    return res;
}