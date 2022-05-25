//problem link: https://leetcode.com/problems/partition-list/

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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL) return NULL;
        ListNode list1=ListNode();
        ListNode list2=ListNode();
        ListNode *less=&list1;
        ListNode *more=&list2;
        ListNode *curr=head;
        while(curr!=NULL){            
            if(curr->val<x) less=less->next=curr;
            else more=more->next=curr;
            curr=curr->next;
        }
        more->next=NULL;
        less->next=list2.next;
        return list1.next;
    }
};