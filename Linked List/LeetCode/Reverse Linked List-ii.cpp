//problem link: https://leetcode.com/problems/reverse-linked-list-ii/

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
    ListNode* reverseKList(ListNode *head, int k){
        //reverse the first k nodes in a linked list
        ListNode *prev=NULL;
        ListNode *curr=head;
        for(int i=0;i<k;i++){
            ListNode *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head->next=curr;
        return prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        int pos=1;
        ListNode *curr=head;
        while(pos<left-1){
            curr=curr->next;
            pos++;
        }
        if(left==1) head=reverseKList(head,right-left+1);
        else curr->next=reverseKList(curr->next,right-left+1);
        return head;
    }
};