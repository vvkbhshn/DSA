//problem link: https://www.interviewbit.com/problems/list-cycle/

ListNode* Solution::detectCycle(ListNode* A) {
    if(A==NULL) return NULL;
    ListNode *slow=A;
    ListNode *fast=A;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) break;
    }
    if(slow!=fast) return NULL;
    slow=A;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */