//problem link: https://leetcode.com/problems/maximum-width-of-binary-tree/

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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int res=0;        
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size(), s=-1, e=-1, firstIndex=-1;
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front().first;
                int index=q.front().second;
                q.pop();
                //incase of sparse trees the width will drastically increase
                //[11...15] can be represented as [0...4]
                //so we subtract it by the first index
                if(firstIndex==-1) firstIndex=index;
                index=index-firstIndex;                
                if(s==-1) s=e=index;
                else e=index;
                if(curr->left) q.push({curr->left,(long long)2*index+1});
                if(curr->right) q.push({curr->right,(long long)2*index+2});           
            }
            res=max(res,e-s+1);
        }
        return res;
    }
};