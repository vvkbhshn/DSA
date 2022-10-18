//problem link: https://www.interviewbit.com/problems/bst-iterator/

stack<TreeNode*> s;

BSTIterator::BSTIterator(TreeNode *root) {
    while(!s.empty()) s.pop();  
    while(root!=NULL){
        s.push(root);
        root=root->left;
    }  
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return !s.empty();
}

/** @return the next smallest number */
int BSTIterator::next() {
    TreeNode* curr=s.top();
    s.pop();
    int res=curr->val;
    curr=curr->right;
    while(curr!=NULL){
        s.push(curr);
        curr=curr->left;
    }
    return res;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */