//problem link: https://www.interviewbit.com/problems/construct-bst-from-preorder/

TreeNode* solve(vector<int> &A, int &index, int lo, int hi){
    if(index==A.size()) return NULL;
    int val=A[index];
    if(val<lo || val>hi) return NULL;
    index++;
    TreeNode* root=new TreeNode(val);
    root->left=solve(A,index,lo,val);
    root->right=solve(A,index,val,hi);
    return root;
} 

// TreeNode* solve2(vector<int> &A, vector<int> &nextGreater, int lo, int hi){
//     if(lo>hi) return NULL;    
//     TreeNode* root=new TreeNode(A[lo]);
//     int index=nextGreater[lo];
//     root->left=solve2(A,nextGreater,lo+1,index-1);
//     root->right=solve2(A,nextGreater,index,hi);
//     return root;
// }

TreeNode* Solution::constructBST(vector<int> &A) {
    // Method-1;
    if(A.empty()) return NULL;
    int index=0;
    return solve(A,index,INT_MIN,INT_MAX);    
    
    // Method-2
    // if(A.empty()) return NULL;
    // int n=A.size();
    // vector<int> nextGreater(n);
    // stack<int> s;
    // for(int i=n-1;i>=0;i--){
    //     while(!s.empty() && A[i]>A[s.top()]) s.pop();
    //     if(s.empty()) nextGreater[i]=n;
    //     else nextGreater[i]=s.top();
    //     s.push(i);
    // }
    // return solve2(A,nextGreater,0,A.size()-1);
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
