//problem link: https://leetcode.com/problems/binary-tree-paths/

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
    void findPath(TreeNode* root, string &temp, vector<string> &res){
        if(root->left==NULL && root->right==NULL){            
            res.push_back(temp);
            return;
        }              
        int n=temp.length();
        if(root->left!=NULL){
            temp+="->"+to_string(root->left->val);
            findPath(root->left,temp,res);
            temp.erase(temp.begin()+n,temp.end());
        }
        if(root->right!=NULL){
            temp+="->"+to_string(root->right->val);
            findPath(root->right,temp,res);
            temp.erase(temp.begin()+n,temp.end());
        }                  
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL) return {};
        vector<string> res;
        string temp=to_string(root->val);
        findPath(root,temp,res);
        return res;
    }
};
