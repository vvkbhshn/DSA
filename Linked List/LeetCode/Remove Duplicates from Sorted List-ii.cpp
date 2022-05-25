//problem link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
    ListNode* deleteDuplicates(ListNode* head) {        
        ListNode *start=new ListNode();
        start->next=head;
        ListNode *prev=start;
        ListNode *curr=head;
        while(curr!=NULL && curr->next!=NULL){
            if(curr->next->val==curr->val){
                while(curr!=NULL && curr->next!=NULL && curr->next->val==curr->val){
                    ListNode *temp=curr->next;                    
                    curr->next=curr->next->next;
                    delete (temp);
                }
                ListNode *next=curr->next;
                delete (curr);
                curr=prev->next=next;
            }
            else{
                prev=curr;
                curr=curr->next;
            }            
        }
        return start->next;
    }
};