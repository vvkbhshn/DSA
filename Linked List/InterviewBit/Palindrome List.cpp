//problem link: https://www.interviewbit.com/problems/palindrome-list/
 
ListNode *reverseList(ListNode *head){
    if(head==NULL) return head;
    ListNode *curr=head;
    ListNode *prev=NULL;
    while(curr!=NULL){
        ListNode *next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
} 
 
int Solution::lPalin(ListNode* A) {
    if(A==NULL || A->next==NULL) return 1;
    ListNode *slow=A;
    ListNode *fast=A->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    fast=reverseList(slow->next);
    slow->next=NULL;
    slow=A;
    while(slow!=NULL && fast!=NULL){
        if(slow->val!=fast->val) return 0;
        slow=slow->next;
        fast=fast->next;
    }
    return 1;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */