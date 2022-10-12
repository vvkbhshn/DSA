//problem link: https://www.interviewbit.com/problems/rotate-list/

ListNode* Solution::rotateRight(ListNode* A, int B) {
    if(A==NULL || A->next==NULL) return A;
    int n=0;
    for(ListNode *curr=A; curr!=NULL; curr=curr->next) n++;
    B=B%n;
    if(B==0) return A;
    ListNode *curr1=A;
    ListNode *curr2=A;
    for(int i=0;i<B;i++) curr2=curr2->next;
    while(curr2->next!=NULL){
        curr1=curr1->next;
        curr2=curr2->next;
    }
    ListNode *head=curr1->next;
    curr1->next=NULL;
    curr2->next=A;
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