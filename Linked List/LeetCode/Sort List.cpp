//problem link: https://leetcode.com/problems/sort-list/

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
    
    ListNode* merge(ListNode* curr1, ListNode* curr2){
        ListNode *start=new ListNode(0);
        ListNode *tail=start;
        while(curr1!=NULL && curr2!=NULL){
            if(curr1->val<curr2->val){
                tail->next=curr1;
                curr1=curr1->next;
            }
            else{
                tail->next=curr2;
                curr2=curr2->next;
            }
            tail=tail->next;
        }
        if(curr1!=NULL) tail->next=curr1;
        else tail->next=curr2;
        ListNode *head=start->next;
        delete (start);
        return head;
    }
    
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;        
        
        // [MERGE SORT method]
        // find the middle node
        ListNode *slow=head;
        ListNode *fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow->next;
        slow->next=NULL;
        slow=head;
        
        //sort the left and right halves of the list
        slow=sortList(slow);
        fast=sortList(fast);
        
        //merge the left and right list
        head=merge(slow,fast);        
        return head;
    }
};