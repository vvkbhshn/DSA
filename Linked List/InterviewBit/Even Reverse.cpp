//problem link: https://www.interviewbit.com/problems/even-reverse/
 
ListNode* reverseList(ListNode *head){
    ListNode *prev=NULL;
    ListNode *curr=head;
    while(curr!=NULL){
        ListNode *next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
} 

ListNode* mergeLists(ListNode* A, ListNode *B){
    ListNode *head=A;
    while(A!=NULL && B!=NULL){
        ListNode *nextA=A->next;
        ListNode *nextB=B->next;
        A->next=B;
        B->next=nextA;
        A=nextA;
        B=nextB;
    }
    return head;
}
 
ListNode* Solution::solve(ListNode* A) {
    if(A==NULL || A->next==NULL) return A;
    ListNode *oddNodes=A;
    ListNode *evenNodes=A->next;
    ListNode *curr1=oddNodes;
    ListNode *curr2=evenNodes;
    ListNode *curr=A->next->next;
    while(curr!=NULL){
        curr1->next=curr;
        curr1=curr1->next;
        curr2->next=curr->next;
        curr2=curr2->next;
        if(curr2!=NULL) curr=curr2->next;
        else break;
    }
    curr1->next=NULL;
    evenNodes=reverseList(evenNodes);
    ListNode *head=mergeLists(oddNodes,evenNodes);
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