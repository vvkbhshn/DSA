//problem link: https://www.interviewbit.com/problems/merge-two-sorted-lists/

ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    if(A==NULL) return B;
    else if(B==NULL) return A;
    ListNode *head=NULL;
    ListNode *curr=NULL;
    if(A->val<B->val){
        head=curr=A;
        A=A->next;
    }
    else{
        head=curr=B;
        B=B->next;
    }
    while(A!=NULL && B!=NULL){
        if(A->val<B->val){
            curr->next=A;
            A=A->next;
        }
        else{
            curr->next=B;
            B=B->next;
        }
        curr=curr->next;
    }
    if(A!=NULL) curr->next=A;
    else if(B!=NULL) curr->next=B;
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