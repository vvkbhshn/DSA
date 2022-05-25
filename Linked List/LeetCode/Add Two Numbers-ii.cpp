//problem link: https://leetcode.com/problems/add-two-numbers-ii/

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
    
    ListNode *reverseList(ListNode *head){
        ListNode *prev=NULL;
        ListNode *curr=head;
        while(curr!=NULL){
            ListNode *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Method-1:
        ListNode *curr1=reverseList(l1);
        ListNode *curr2=reverseList(l2);
        ListNode *head=new ListNode(-1);
        ListNode *tail=head;
        int carry=0;
        while(curr1!=NULL || curr2!=NULL || carry>0){
            int sum=0;
            if(curr1!=NULL){
                sum+=curr1->val;
                curr1=curr1->next;
            }
            if(curr2!=NULL){
                sum+=curr2->val;
                curr2=curr2->next;
            }
            sum+=carry;
            carry=sum/10;
            tail->next=new ListNode(sum%10);
            tail=tail->next;          
        }
        ListNode *temp=head;
        head=head->next;
        delete (temp);
        head=reverseList(head);
        return head;
        
        // Method-2: using STACK data structure
        // ListNode *curr1=l1;
        // ListNode *curr2=l2;
        // stack<ListNode*> s1;
        // stack<ListNode*> s2;
        // while(curr1!=NULL){
        //     s1.push(curr1);
        //     curr1=curr1->next;
        // }
        // while(curr2!=NULL){
        //     s2.push(curr2);
        //     curr2=curr2->next;
        // }
        // ListNode *head=new ListNode(-1);
        // ListNode *tail=head;
        // int carry=0;
        // while(!s1.empty() || !s2.empty() || carry>0){
        //     int sum=0;
        //     if(!s1.empty()){
        //         sum+=s1.top()->val;
        //         s1.pop();
        //     }
        //     if(!s2.empty()){
        //         sum+=s2.top()->val;
        //         s2.pop();
        //     }
        //     sum+=carry;
        //     carry=sum/10;
        //     tail->next=new ListNode(sum%10);
        //     tail=tail->next;
        // }
        // ListNode *temp=head;
        // head=head->next;
        // delete (temp);
        // head=reverseList(head);
        // return head;
    }
};