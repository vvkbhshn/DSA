//problem link: https://leetcode.com/problems/binary-search-tree-iterator/

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

// Method-1:
class BSTIterator {
private:
    stack<TreeNode*> s;
    TreeNode* curr;
    
public:   
    BSTIterator(TreeNode* root) {
        curr=root;
    }
    
    int next() {
        while(curr!=NULL){
            s.push(curr);
            curr=curr->left;
        }
        TreeNode* next=s.top();
        s.pop();
        curr=next->right;
        return next->val;
    }
    
    bool hasNext() {
        return curr!=NULL || !s.empty();
    }
};

// Method-2:
// class BSTIterator {
// private:
//     vector<int> inorder;
//     int index;
    
// public:
//     void traverse(TreeNode* root){
//         if(root==NULL) return;
//         traverse(root->left);
//         inorder.push_back(root->val);
//         traverse(root->right);
//     }
    
//     BSTIterator(TreeNode* root) {
//         traverse(root);
//         index=-1;
//     }
    
//     int next() {
//         return inorder[++index];
//     }
    
//     bool hasNext() {
//         return (index+1)<inorder.size();
//     }
// };

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */