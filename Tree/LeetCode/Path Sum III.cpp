//problem link: https://leetcode.com/problems/path-sum-iii/

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
    int traverse(TreeNode* root, unordered_map<long,long> &mp, int &targetSum, long currSum){
        if(root==NULL) return 0;
        currSum+=root->val;        
        int res=mp[currSum-targetSum]; 
        mp[currSum]++;
        res+=traverse(root->left,mp,targetSum,currSum);
        res+=traverse(root->right,mp,targetSum,currSum);
        mp[currSum]--;
        return res;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        unordered_map<long,long> mp;
        mp[0]=1; //for path from root to node
        return traverse(root,mp,targetSum,0);
    }
};