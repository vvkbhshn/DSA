//problem link: https://www.interviewbit.com/problems/vertical-sum-of-a-binary-tree/
 
void traverse(TreeNode* A, int dist, int &leftDist, int &rightDist){
    if(A==NULL) return;
    leftDist=min(leftDist,dist);
    rightDist=max(rightDist,dist);
    traverse(A->left,dist-1,leftDist,rightDist);
    traverse(A->right,dist+1,leftDist,rightDist);
}

void calculateSum(TreeNode *A, vector<int> &res, int dist, int &leftDist){
    if(A==NULL) return;
    res[dist-leftDist]+=A->val;
    calculateSum(A->left,res,dist-1,leftDist);
    calculateSum(A->right,res,dist+1,leftDist);
}
 
vector<int> Solution::verticalSum(TreeNode* A) {
    vector<int> res;
    if(A==NULL) return res;
    int leftDist=0, rightDist=0;
    traverse(A,0,leftDist,rightDist);
    res.resize(rightDist-leftDist+1);
    calculateSum(A,res,0,leftDist);
    return res;
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