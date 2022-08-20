//problem link: https://leetcode.com/problems/merge-two-sorted-lists/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        ListNode *head=NULL, *curr=NULL;
        if(list1->val<list2->val){
            head=curr=list1;
            list1=list1->next;
        }
        else{
            head=curr=list2;
            list2=list2->next;
        }
        while(list1!=NULL && list2!=NULL){
            if(list1->val<list2->val){
                curr->next=list1;
                curr=list1;
                list1=list1->next;
            }
            else{
                curr->next=list2;
                curr=list2;
                list2=list2->next;
            }
        }
        if(list1!=NULL) curr->next=list1;
        else if(list2!=NULL) curr->next=list2;
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