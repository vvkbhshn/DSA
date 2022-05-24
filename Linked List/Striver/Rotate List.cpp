//problem link: https://leetcode.com/problems/rotate-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        int n=1;
        ListNode *curr=head;
        ListNode *tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
            n++;
        }
        k=k%n;
        if(k==0) return head;
        tail->next=head;
        for(int i=0;i<n-k-1;i++) curr=curr->next;
        head=curr->next;
        curr->next=NULL;
        return head;
    }
};