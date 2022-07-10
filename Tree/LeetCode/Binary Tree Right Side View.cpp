//problem link: https://leetcode.com/problems/binary-tree-right-side-view/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    
    void rightView(TreeNode* root, vector<int> &res, int currDepth){
        if(root==NULL) return;
        //clever way to check for the no. of elements present in tha array
        //for level X, if arr.size()=X+1, that means the req 'right node' was already found for that level, otherwise current node is the req node
        if(currDepth==res.size()) res.push_back(root->val);
        rightView(root->right,res,currDepth+1);
        rightView(root->left,res,currDepth+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;        
        
        // Method-1: iterative
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            TreeNode* curr;
            for(int i=0;i<sz;i++){
                curr=q.front();
                q.pop();
                if(i==sz-1) res.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        
        // Method-2: recursive
        // rightView(root,res,0);
        
        return res;
    }
};