//problem link: https://www.interviewbit.com/problems/populate-next-right-pointers-tree/
 
void Solution::connect(TreeLinkNode* A) {
    // Method-1: O(1) space
    if(A==NULL) return;
    TreeLinkNode* curr=A;    
    while(curr!=NULL){
        TreeLinkNode* prev=NULL;
        TreeLinkNode* nextLevel=NULL;
        while(curr!=NULL){
            if(curr->left){
                if(prev==NULL){
                    nextLevel=curr->left;
                    prev=curr->left;                    
                }
                else{
                    prev->next=curr->left;
                    prev=prev->next;
                }
            }
            if(curr->right){
                if(prev==NULL){
                    nextLevel=curr->right;
                    prev=curr->right;
                }
                else{
                    prev->next=curr->right;
                    prev=prev->next;
                }
            }            
            curr=curr->next;
        }
        curr=nextLevel;
    }
    
    // Method-2: O(width) space
    // if(A==NULL) return;
    // queue<TreeLinkNode*> q;
    // q.push(A);
    // while(!q.empty()){
    //     TreeLinkNode* prev=NULL;
    //     int n=q.size();
    //     while(n--){
    //         TreeLinkNode* curr=q.front();
    //         q.pop();
    //         if(prev!=NULL) prev->next=curr;
    //         prev=curr;
    //         if(curr->left) q.push(curr->left);
    //         if(curr->right) q.push(curr->right);
    //     }
    // }
}

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */