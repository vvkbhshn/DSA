//problem link: https://leetcode.com/problems/reorder-list/

class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL) return;
        ListNode *slow=head, *fast=head;
        ListNode *prev=NULL;
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        ListNode *l1=head;
        ListNode *l2=reverse(slow);
        merge(l1,l2);
    }
    
    ListNode *reverse(ListNode *head){
        ListNode *prev=NULL;
        while(head!=NULL){
            ListNode *next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;
    }
    
    void merge(ListNode *l1, ListNode *l2){
        while(l1!=NULL){
            ListNode *next1=l1->next;
            ListNode *next2=l2->next;
            l1->next=l2;
            if(next1==NULL) break;
            l2->next=next1;
            l1=next1;
            l2=next2;
        }
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