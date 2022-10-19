//problem link: https://www.interviewbit.com/problems/postorder-traversal/

// void postorder(TreeNode* A, vector<int> &res){
//     if(A==NULL) return;
//     postorder(A->left,res);
//     postorder(A->right,res);
//     res.push_back(A->val);
// }

vector<int> Solution::postorderTraversal(TreeNode* A) {
    // Method-1: Morris traversal (reverse)
    vector<int> res;
    TreeNode* curr=A;
    while(curr!=NULL){
        if(curr->right==NULL){
            res.push_back(curr->val);
            curr=curr->left;
        }
        else{
            TreeNode* next=curr->right;
            while(next->left && next->left!=curr) next=next->left;
            if(next->left==NULL){
                res.push_back(curr->val);
                next->left=curr;
                curr=curr->right;
            }
            else{
                next->left=NULL;
                curr=curr->left;
            }
        }
    }
    reverse(res.begin(),res.end());
    return res;
    
    // Method-2: using stack
    // vector<int> res;
    // if(A==NULL) return res;
    // TreeNode* curr=A;
    // stack<TreeNode*> s;
    // s.push(A);
    // while(!s.empty()){
    //     curr=s.top();
    //     s.pop();
    //     res.push_back(curr->val);
    //     if(curr->left) s.push(curr->left);
    //     if(curr->right) s.push(curr->right);
    // }
    // reverse(res.begin(),res.end());
    // return res;
    
    // Method-3: using Recursion
    // vector<int> res;
    // postorder(A,res);
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