//problem link: https://www.interviewbit.com/problems/sort-binary-linked-list/
 
ListNode* Solution::solve(ListNode* A) {
    if(A==NULL) return A;
    int num0=0, num1=0;
    ListNode* curr=A;
    while(curr!=NULL){
        if(curr->val==0) num0++;
        else num1++;
        curr=curr->next;
    }
    curr=A;
    while(curr!=NULL){
        if(num0>0) curr->val=0, num0--;
        else if(num1>0) curr->val=1, num1--;
        curr=curr->next;
    }
    return A;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */