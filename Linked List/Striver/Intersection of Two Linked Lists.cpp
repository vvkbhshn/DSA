//problem link: https://leetcode.com/problems/intersection-of-two-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;
        int len1=0, len2=0;
        ListNode *curr1=headA;
        ListNode *curr2=headB;
        while(curr1!=NULL){
            len1++;
            curr1=curr1->next;
        }
        while(curr2!=NULL){
            len2++;
            curr2=curr2->next;
        }
        curr1=headA;
        curr2=headB;
        int diff=abs(len1-len2);
        for(int i=0;i<diff;i++){
            if(len1<len2) curr2=curr2->next;
            else if(len2<len1) curr1=curr1->next;
        }
        while(curr1!=NULL && curr2!=NULL){
            if(curr1==curr2) return curr1;
            curr1=curr1->next;
            curr2=curr2->next;
        }               
        return NULL;        
    }
};  