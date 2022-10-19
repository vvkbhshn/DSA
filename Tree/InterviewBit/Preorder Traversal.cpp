//problem link: https://www.interviewbit.com/problems/preorder-traversal/
 
// void preorder(TreeNode* A, vector<int> &res){
//     if(A==NULL) return;
//     res.push_back(A->val);
//     preorder(A->left,res);    
//     preorder(A->right,res);
// }  
 
vector<int> Solution::preorderTraversal(TreeNode* A) {
    // Method-1: Morris traversal
    vector<int> res;
    if(A==NULL) return res;
    TreeNode* curr=A;
    while(curr!=NULL){
        if(curr->left==NULL){
            res.push_back(curr->val);
            curr=curr->right;
        }
        else{
            TreeNode* prev=curr->left;
            while(prev->right && prev->right!=curr) prev=prev->right;
            if(prev->right==NULL){
                res.push_back(curr->val);
                prev->right=curr;
                curr=curr->left;
            }
            else{
                prev->right=NULL;
                curr=curr->right;
            }
        }
    }
    return res;
    
    // Method-2: using stack
    // vector<int> res;
    // if(A==NULL) return res;
    // TreeNode *curr=A;
    // stack<TreeNode*> s;
    // s.push(A);
    // while(!s.empty()){
    //     curr=s.top();
    //     s.pop();
    //     res.push_back(curr->val);
    //     if(curr->right) s.push(curr->right);
    //     if(curr->left) s.push(curr->left);
    // }
    // return res; 
    
    // Method-3: using recursion
    // vector<int> res;
    // preorder(A,res);
    // return res;
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