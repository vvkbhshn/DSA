//problem link: https://www.interviewbit.com/problems/reorder-list/
 
ListNode *reverseList(ListNode *A){
    ListNode *curr=A;
    ListNode *prev=NULL;
    while(curr!=NULL){
        ListNode *next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
} 

void mergeLists(ListNode *A, ListNode *B){
    while(A!=NULL && B!=NULL){
        ListNode *nextA=A->next;
        ListNode *nextB=B->next;
        A->next=B;
        B->next=nextA;
        A=nextA;
        B=nextB;
    }
}
 
ListNode* Solution::reorderList(ListNode* A) {
    if(A==NULL || A->next==NULL) return A;
    ListNode *slow=A, *fast=A->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    fast=reverseList(slow->next);
    slow->next=NULL;
    slow=A;
    mergeLists(slow,fast);
    return A;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */