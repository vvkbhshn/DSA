//problem link: https://practice.geeksforgeeks.org/problems/move-last-element-to-front-of-a-linked-list/1?page=5&category%5B%5D=Linked%20List&sortBy=submissions

class Solution{
public:
    ListNode *moveToFront(ListNode *head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* curr=head;
        while(curr->next->next!=NULL){
            curr=curr->next;
        }
        ListNode* tail=curr->next;
        curr->next=NULL;
        tail->next=head;
        return tail;
    }
};