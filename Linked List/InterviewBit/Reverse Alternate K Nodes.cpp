//problem link: https://www.interviewbit.com/problems/reverse-alternate-k-nodes/

ListNode* reverseK(ListNode *A, int B, bool rev){
   if(A==NULL || A->next==NULL || B==1) return A;
    ListNode *curr=A;
    ListNode *prev=NULL;
    ListNode *head=A;
    if(rev){
        for(int i=0;i<B && curr!=NULL;i++){
            ListNode *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        A->next=reverseK(curr,B,!rev);
        head=prev;
    }
    else{
        for(int i=0;i<B-1 && curr!=NULL;i++){
            curr=curr->next;
        }
        curr->next=reverseK(curr->next,B,!rev);
    }
    return head; 
}
 
ListNode* Solution::solve(ListNode* A, int B) {
    return reverseK(A,B,true);
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */