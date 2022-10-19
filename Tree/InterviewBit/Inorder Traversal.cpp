//problem link: https://www.interviewbit.com/problems/inorder-traversal/
 
// void inorder(TreeNode* A, vector<int> &res){
//     if(A==NULL) return;
//     inorder(A->left,res);
//     res.push_back(A->val);
//     inorder(A->right,res);
// }  
 
vector<int> Solution::inorderTraversal(TreeNode* A) {
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
                prev->right=curr;
                curr=curr->left;
            }
            else{
                res.push_back(curr->val);
                prev->right=NULL;
                curr=curr->right;
            }
        }
    }
    return res;
    
    // Method-2: using stack
    // vector<int> res;
    // if(A==NULL) return res;
    // TreeNode* curr=A;
    // stack<TreeNode*> s;
    // while(!s.empty() || curr!=NULL){
    //     while(curr!=NULL){
    //         s.push(curr);
    //         curr=curr->left;
    //     }
    //     curr=s.top();
    //     s.pop();
    //     res.push_back(curr->val);
    //     curr=curr->right;
    // }
    // return res;
    
    // Method-3: using Recursion
    // vector<int> res;
    // inorder(A,res);
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