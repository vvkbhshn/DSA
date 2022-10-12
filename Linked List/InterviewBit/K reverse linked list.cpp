//problem link: https://www.interviewbit.com/problems/k-reverse-linked-list/

ListNode* Solution::reverseList(ListNode* A, int B) {
    // Method-1:
    if(A==NULL || A->next==NULL || B==1) return A;
    int K=B;
    ListNode* prev=NULL;
    ListNode* curr=A;
    while(curr!=NULL && K>0){
        ListNode *next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        K--;
    }
    A->next=reverseList(curr,B);
    return prev;
    
    // Method-2:
    // if(A==NULL || A->next==NULL || B==1) return A;
    // ListNode *prev=NULL;
    // ListNode *curr=A;
    // ListNode *head=NULL;
    // while(curr!=NULL){
    //     ListNode *currNode=curr;
    //     ListNode *prevNode=NULL;
    //     for(int i=0;i<B;i++){
    //         ListNode *nextNode=currNode->next;
    //         currNode->next=prevNode;
    //         prevNode=currNode;
    //         currNode=nextNode;
    //     }
    //     if(prev!=NULL) prev->next=prevNode;
    //     else head=prevNode;
    //     prev=curr;
    //     curr=currNode;
    // }
    // return head;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */