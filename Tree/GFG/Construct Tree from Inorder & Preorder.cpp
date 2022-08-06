//problem link: https://practice.geeksforgeeks.org/problems/construct-tree-1/1

class Solution{
    public:    
    Node* solve(int in[], int pre[], int n, int &index, int l, int r){
        if(l>r || index==n) return NULL;
        Node *root=new Node(pre[index]);
        for(int i=l;i<=r;i++){
            if(in[i]==pre[index]){
                index++;
                root->left=solve(in,pre,n,index,l,i-1);
                root->right=solve(in,pre,n,index,i+1,r);
                break;
            }
        }
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int index=0;
        return solve(in,pre,n,index,0,n-1);
    }
};