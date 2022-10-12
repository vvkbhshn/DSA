//problem link: https://www.interviewbit.com/problems/sort-list/
 
ListNode* mergeLists(ListNode* A, ListNode* B){
    if(A==NULL) return B;
    else if(B==NULL) return A;
    ListNode* head=new ListNode(-1);
    ListNode *curr=head;
    ListNode* curr1=A, *curr2=B;
    while(curr1!=NULL && curr2!=NULL){
        if(curr1->val<curr2->val){
            curr->next=curr1;
            curr1=curr1->next;
        }
        else{
            curr->next=curr2;
            curr2=curr2->next;
        }
        curr=curr->next;
    }
    if(curr1!=NULL) curr->next=curr1;
    else if(curr2!=NULL) curr->next=curr2;
    curr=head;
    head=head->next;
    delete curr;
    return head;
}
 
ListNode* Solution::sortList(ListNode* A) {
    if(A==NULL || A->next==NULL) return A;
    ListNode *slow=A;
    ListNode *fast=A->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    fast=slow->next;
    slow->next=NULL;
    slow=A;
    slow=sortList(slow);
    fast=sortList(fast);
    ListNode *head=mergeLists(slow,fast); 
    return head;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */