//problem link: https://leetcode.com/problems/house-robber-iii/

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
    
    int dfs(TreeNode* root, bool toSteal, unordered_map<TreeNode*,pair<int,int>> &mp){
        if(root==NULL) return 0;
        if(toSteal && mp[root].first>0) return mp[root].first;
        if(!toSteal && mp[root].second>0) return mp[root].second;
        int res1=0, res2=0;
        if(toSteal){
            int x1=root->val+dfs(root->left,false,mp)+dfs(root->right,false,mp);
            int x2=dfs(root->left,true,mp)+dfs(root->right,true,mp);            
            res1=max(x1,x2);            
        }
        else{
            res2=dfs(root->left,true,mp)+dfs(root->right,true,mp);
        }
        if(toSteal) return mp[root].first=max(res1,res2);
        else return mp[root].second=max(res1,res2);
    }
    
    // vector<int> solve(TreeNode* root){
    //     if(root==NULL) return {0,0};
    //     vector<int> left=solve(root->left);
    //     vector<int> right=solve(root->right);
    //     vector<int> res(2);
    //     //res[0] = amount when we dont steel the 'root' house
    //     res[0]=max(left[0],left[1])+max(right[0],right[1]);
    //     //res[1] = amount when we steal the 'root' house
    //     res[1]=root->val+left[0]+right[0];
    //     return res;
    // }
    
    int rob(TreeNode* root) {
        // Method-1: [top-down DP]
        unordered_map<TreeNode*,pair<int,int>> mp;
        return max(dfs(root,true,mp),dfs(root,false,mp));
        
        // Method-2:
        // vector<int> res=solve(root);
        // return max(res[0],res[1]);
    }
};