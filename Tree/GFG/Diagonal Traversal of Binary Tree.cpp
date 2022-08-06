//problem link: https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

vector<int> diagonal(Node *root)
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
           while(curr!=NULL){
               res.push_back(curr->data);
               if(curr->left) q.push(curr->left);
               curr=curr->right;
           }
       }
   }
   return res;
}