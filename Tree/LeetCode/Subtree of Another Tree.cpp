//problem link: https://leetcode.com/problems/subtree-of-another-tree/

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
    
    bool isIdentical(TreeNode* root1, TreeNode* root2){
        if(root1==NULL || root2==NULL) return root1==root2;
        return (root1->val==root2->val && 
                isIdentical(root1->left,root2->left) && isIdentical(root1->right, root2->right));
    }
    
    int getDepth(TreeNode* root, TreeNode* subRoot, int reqDepth, bool &found){
        if(root==NULL) return 0;
        int currDepth = 1+max(getDepth(root->left,subRoot,reqDepth,found),
                              getDepth(root->right,subRoot,reqDepth,found));
        //only checking for the subtree with the same depth as the given subtree
        if(currDepth==reqDepth && !found && isIdentical(root,subRoot)) found=true;
        return currDepth;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot==NULL) return true;
        else if(root==NULL || subRoot==NULL) return false;        
        
        //Method-1:        
        bool found=false;
        int reqDepth=getDepth(subRoot,NULL,-1,found);
        getDepth(root,subRoot,reqDepth,found);
        return found;
        
        //Method-2:
        // if(root->val==subRoot->val && isIdentical(root,subRoot)) return true;
        // return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};