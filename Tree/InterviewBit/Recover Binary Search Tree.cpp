//problem link: https://www.interviewbit.com/problems/recover-binary-search-tree/

//Morris Traversal
vector<int> Solution::recoverTree(TreeNode* A) {
    vector<int> res={-1,-1};
    TreeNode *prev=NULL;
    TreeNode *curr=A;
    while(curr!=NULL){
        if(curr->left==NULL){
            if(prev!=NULL){
                if(prev->val>curr->val){
                    if(res[1]==-1) res[1]=prev->val;
                    res[0]=curr->val;
                } 
            }
            prev=curr;
            curr=curr->right;
        }
        else{
            TreeNode *temp=curr->left;
            while(temp->right!=NULL && temp->right!=curr) temp=temp->right;
            if(temp->right==NULL){
                temp->right=curr;
                curr=curr->left;
            }
            else{
                if(prev!=NULL){
                    if(prev->val>curr->val){
                        if(res[1]==-1) res[1]=prev->val;
                        res[0]=curr->val;
                    } 
                } 
                prev=curr;
                temp->right=NULL;
                curr=curr->right;
            }
        }
    }
    return res;
}

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */