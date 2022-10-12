//problem link: https://www.interviewbit.com/problems/remove-nth-node-from-list-end/

ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    // Method-1:
    if(A==NULL) return A;
    ListNode *curr=A;
    ListNode *prev=A;
    while(B-- && curr!=NULL) curr=curr->next;
    if(curr==NULL){
        ListNode *temp=A;
        A=A->next;
        delete temp;
        return A;
    }
    while(curr->next!=NULL){
        prev=prev->next;
        curr=curr->next;
    }
    ListNode *temp=prev->next;
    prev->next=prev->next->next;
    delete temp;
    return A;
    
    // Method-2:
    // if(A==NULL) return A;
    // int len=0;
    // ListNode *curr=A;
    // while(curr!=NULL){
    //     len++;
    //     curr=curr->next;
    // }
    // len-=B;
    // if(len<=0){
    //     ListNode *temp=A;
    //     A=A->next;
    //     delete temp;
    // }
    // else{
    //     curr=A;
    //     for(int i=0;i<len-1;i++) curr=curr->next;
    //     ListNode *temp=curr->next;
    //     curr->next=curr->next->next;
    //     delete temp;
    // }
    // return A;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */