//problem link: https://leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;        
        ListNode *start=new ListNode();
        ListNode *prev=start;
        ListNode *curr=head;
        start->next=head;
        while(curr!=NULL && curr->next!=NULL){
            ListNode *next=curr->next->next;
            prev->next=curr->next;
            curr->next->next=curr;
            curr->next=next;
            prev=curr;
            curr=curr->next;
        }
        curr=start->next;
        delete start;
        return  curr;
    }
};