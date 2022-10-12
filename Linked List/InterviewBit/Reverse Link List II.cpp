//problem link: https://www.interviewbit.com/problems/reverse-link-list-ii/
 
ListNode* Solution::reverseBetween(ListNode* A, int m, int n) {
    ListNode *curr=A, *end=A;
    ListNode *prevNode=NULL, *nextNode=NULL;
    for(int i=0;i<m-1;i++){
        prevNode=curr;
        curr=curr->next;
    }
    ListNode *prev=NULL;
    for(int i=0;i<=n-m;i++){
        nextNode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextNode;
    }
    if(m==1){
        A->next=curr;
        return prev;
    }
    else{
        prevNode->next->next=curr;
        prevNode->next=prev;
        return A;        
    }
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */