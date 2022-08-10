//problem link: https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

class Solution{
  public:  
    Node* reverseList(Node *head){
        if(head==NULL) return NULL;
        Node* prev=NULL;
        while(head!=NULL){
            Node *next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;
    }

    bool isPalindrome(Node *head)
    {
        Node *slow=head, *fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        Node *head2=reverseList(slow->next);
        slow->next==NULL;
        while(head!=NULL && head2!=NULL){
            if(head->data!=head2->data) return false;
            head=head->next;
            head2=head2->next;
        }
        return true;
    }
};
