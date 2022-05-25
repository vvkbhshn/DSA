//problem link: https://leetcode.com/problems/odd-even-linked-list/

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
    ListNode* oddEvenList(ListNode* head) {
        ListNode oddList=ListNode(0);
        ListNode evenList=ListNode(0);
        ListNode *odd=&oddList;
        ListNode *even=&evenList; 
        ListNode *curr=head;
        int pos=1;
        while(curr!=NULL){
            if(pos&1){
                odd->next=curr;
                odd=odd->next;
            }
            else{
                even->next=curr;
                even=even->next;
            }
            pos++;
            curr=curr->next;
        }
        even->next=NULL;
        odd->next=evenList.next;
        return oddList.next;
    }
};