//problem link: https://leetcode.com/problems/reorder-list/

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
    
    ListNode *reverseList(ListNode *head){
        ListNode *prev=NULL;
        ListNode *curr=head;
        while(curr!=NULL){
            ListNode *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        
        // Method-1:
        ListNode *start=new ListNode();
        ListNode *slow=start;
        ListNode *fast=start;
        start->next=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=reverseList(slow->next);
        slow->next=NULL;
        slow=head;
        while(fast!=NULL){
            ListNode *curr1=slow->next;
            ListNode *curr2=fast->next;
            slow->next=fast;
            fast->next=curr1;
            slow=curr1;
            fast=curr2;
        }
        
        // Method-2: STACK based solution
        // ListNode *curr=head;
        // stack<ListNode *>s;
        // int len=0;
        // while(curr!=NULL){
        //     s.push(curr);
        //     len++;
        //     curr=curr->next;
        // }
        // curr=head;
        // for(int i=0;i<len/2;i++){
        //     ListNode *temp=s.top();
        //     s.pop();
        //     temp->next=curr->next;
        //     curr->next=temp;
        //     curr=curr->next->next;
        // }
        // curr->next=NULL;
    }
};