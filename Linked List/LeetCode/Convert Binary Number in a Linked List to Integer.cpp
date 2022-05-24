//problem link: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

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
    int getDecimalValue(ListNode* head) {
        
        // Method-1
        int sum=0;
        while(head!=NULL){
            sum*=2;
            sum+=head->val;
            head=head->next;
        }
        return sum;
        
        // Method-2
        // int n=1;
        // ListNode *curr=head;
        // while(curr->next!=NULL){
        //     n++;
        //     curr=curr->next;
        // }
        // n--;
        // int res=0;
        // curr=head;
        // while(curr!=NULL){
        //     if(curr->val==1) res+=(1<<n);
        //     n--;
        //     curr=curr->next;
        // }
        // return res;
    }
};