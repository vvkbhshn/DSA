//problem link: https://leetcode.com/problems/reverse-nodes-in-k-group/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1) return head;
        ListNode *curr=head;
        ListNode *prev=NULL;
        int count=0;
        while(curr!=NULL && count<k){
            curr=curr->next;
            count++;
        }
        if(count==k){
            curr=head;
            while(count--){
                ListNode *next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            head->next=reverseKGroup(curr,k);
            return prev;
        }
        return head;
    }
};

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