//problem link: https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1

class Solution{
  public:
    bool check(Node *root)
    {
        if(root==NULL) return true;
        bool foundPrev=false, foundCurr=false;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                Node* curr=q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                if(curr->left==NULL && curr->right==NULL){
                    if(foundPrev) return false;
                    else foundCurr=true;
                }
            }
            if(foundCurr) foundPrev=true;
        }
        return true;
    }
};