//problem link: https://www.interviewbit.com/problems/kth-node-from-middle/

int Solution::solve(ListNode* A, int B) {
    if(A==NULL || A->next==NULL) return -1;
    int n=0;
    ListNode *slow=A, *fast=A;
    while(fast!=NULL && fast->next!=NULL){
        n++;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(B>n) return -1;
    B=n-B;
    ListNode *curr=A;
    for(int i=0;i<B;i++) curr=curr->next;
    return curr->val; 
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */