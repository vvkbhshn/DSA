//problem link: https://www.interviewbit.com/problems/2sum-binary-tree/

class BST{
    private:
    stack<TreeNode*> s1,s2;
    TreeNode* curr1;
    TreeNode* curr2;
    
    public:
    BST(TreeNode* root){
        curr1=curr2=root;
        while(curr1!=NULL){
            s1.push(curr1);
            curr1=curr1->left;
        }
        while(curr2!=NULL){
            s2.push(curr2);
            curr2=curr2->right;
        }
    }
    
    int next(){
        if(s1.empty()) return 0;
        curr1=s1.top();
        int res=curr1->val;
        s1.pop();
        curr1=curr1->right;
        while(curr1!=NULL){
            s1.push(curr1);
            curr1=curr1->left;
        }
        return res;
    }
    
    int prev(){
        if(s2.empty()) return 0;
        curr2=s2.top();
        int res=curr2->val;
        s2.pop();
        curr2=curr2->left;
        while(curr2!=NULL){
            s2.push(curr2);
            curr2=curr2->right;
        }
        return res;
    }
};

// bool findNodes(TreeNode* A, unordered_set<int> &mp, int &B){
//     if(A==NULL) return false;
//     if(findNodes(A->left,mp,B)) return true;
//     if(mp.find(B-A->val)!=mp.end()) return true;
//     mp.insert(A->val);
//     if(findNodes(A->right,mp,B)) return true;
//     return false;
// } 

 
int Solution::t2Sum(TreeNode* A, int B) {
    // Method-1: O(height) space
    BST bst(A);
    int x=bst.next(), y=bst.prev();
    while(x>0 && y>0 && x<y){
        if(x+y<B) x=bst.next();
        else if(x+y>B) y=bst.prev();
        else return 1;
    }
    return 0;
    
    // Method-2: O(N) space
    // unordered_set<int> mp;
    // if(findNodes(A,mp,B)) return 1;
    // return 0;
    
    // Method-3: O(N) space
    // do the inorder traversal of the BST and store it in an array which will be sorted by default.
    // use two pointer approach on the sorted array to find if a valid pair exists.
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