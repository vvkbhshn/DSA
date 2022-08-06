//problem link: https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1

vector<int> rightView(Node *root)
{
    vector<int> res;
    if(root==NULL) return res;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            Node* curr=q.front();
            q.pop();
            if(i==n-1) res.push_back(curr->data);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    return res;
}