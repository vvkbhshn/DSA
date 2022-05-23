//problem link: https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *prev=NULL;
        ListNode *curr=head;
        int count=0;
        while(curr!=NULL && count<k){
            curr=curr->next;
            count++;
        }
        if(count==k){
            ListNode *curr2=head;
            while(count--){
                ListNode *next=curr2->next;
                curr2->next=prev;
                prev=curr2;
                curr2=next;                
            }
                      
            //recursively call the function to reverse remaining list into K-Groups
            head->next=reverseKGroup(curr,k);
            head=prev;                       
        }
        return head;
    }
};