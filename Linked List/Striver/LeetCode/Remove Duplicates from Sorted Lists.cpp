//problem link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
        
        // Method-1:
        ListNode *curr=head;
        while(curr!=NULL && curr->next!=NULL){
            if(curr->next->val==curr->val){
                ListNode *temp=curr->next;
                curr->next=curr->next->next;
                delete (temp);
            }
            else curr=curr->next;
        }
        return head;
        
        // Method-2:
        // ListNode *prev=head;
        // ListNode *curr=head->next;
        // while(curr!=NULL){
        //     if(curr->val==prev->val){
        //         ListNode *temp=curr;
        //         prev->next=curr->next;
        //         delete (temp);  
        //         curr=prev->next;
        //     }
        //     else{
        //         prev=curr;
        //         curr=curr->next;
        //     }
        // }
        // return head;
    }
};