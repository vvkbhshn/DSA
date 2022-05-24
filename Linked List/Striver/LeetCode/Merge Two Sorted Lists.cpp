//problem link: https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        ListNode *curr1=list1;
        ListNode *curr2=list2;
        ListNode *head=NULL;
        ListNode *tail=NULL;
        
        if(curr1->val<=curr2->val){
            head=curr1;
            curr1=curr1->next;
        }
        else{
            head=curr2;
            curr2=curr2->next;
        }
        tail=head;
        
        while(curr1!=NULL && curr2!=NULL){
            if(curr1->val<=curr2->val){
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
        
        return head;
    }
};