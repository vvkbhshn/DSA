//problem link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;
        
        // Method-1: normal level order traversal using queue
        queue<TreeNode*> q;        
        bool rev=false;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> temp(n);
            TreeNode *curr;
            for(int i=0;i<n;i++){
                curr=q.front();
                q.pop();
                if(rev) temp[n-1-i]=curr->val;
                else temp[i]=curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            rev=!rev;
            res.push_back(temp);
        }
        return res;
        
        // Method-2: using 2 stacks
        // stack<TreeNode*> s1,s2;
        // s1.push(root);
        // while(!s1.empty() || !s2.empty()){
        //     vector<int> temp;
        //     TreeNode* curr;
        //     while(!s1.empty()){
        //         curr=s1.top(); s1.pop();
        //         temp.push_back(curr->val);
        //         if(curr->left) s2.push(curr->left);
        //         if(curr->right) s2.push(curr->right);
        //     }
        //     if(!temp.empty()) res.push_back(temp);
        //     temp.clear();
        //     while(!s2.empty()){
        //         curr=s2.top(); s2.pop();
        //         temp.push_back(curr->val);
        //         if(curr->right) s1.push(curr->right);
        //         if(curr->left) s1.push(curr->left);
        //     }
        //     if(!temp.empty()) res.push_back(temp);
        // }
        // return res;
    }
};