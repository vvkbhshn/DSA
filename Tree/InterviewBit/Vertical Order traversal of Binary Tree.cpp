//problem link: https://www.interviewbit.com/problems/vertical-order-traversal-of-binary-tree/
 
void traverse(TreeNode* A, int dist, int &minDist, int &maxDist){
    if(A==NULL) return;
    minDist=min(minDist,dist);
    maxDist=max(maxDist,dist);
    traverse(A->left,dist-1,minDist,maxDist);
    traverse(A->right,dist+1,minDist,maxDist);
} 
 
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    vector<vector<int>> res;
    if(A==NULL) return res;    
    int minDist=0, maxDist=0;
    traverse(A,0,minDist,maxDist);
    res.resize(maxDist-minDist+1);
    queue<pair<TreeNode*,int>> q;
    q.push({A,0});
    while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            auto p=q.front();
            q.pop();
            TreeNode* curr=p.first;
            int dist=p.second;
            res[dist-minDist].push_back(curr->val);
            if(curr->left!=NULL) q.push({curr->left,dist-1});
            if(curr->right!=NULL) q.push({curr->right,dist+1});
        }
    }
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