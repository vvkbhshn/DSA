//problem link: https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/

ListNode* Solution::swapPairs(ListNode* A) {
    if(A==NULL || A->next==NULL) return A;
    ListNode *head=NULL;
    ListNode *curr=A;
    ListNode *prev=NULL;
    while(curr!=NULL && curr->next!=NULL){
        ListNode *nextToNextNode=curr->next->next;
        ListNode *nextNode=curr->next;
        nextNode->next=curr;
        curr->next=nextToNextNode;
        if(prev!=NULL) prev->next=nextNode;
        else head=nextNode;
        prev=curr;
        curr=nextToNextNode;
    }
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