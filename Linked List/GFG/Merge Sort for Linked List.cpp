//problem link: https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1

class Solution{
  public:
  
    Node* merge(Node* head1, Node* head2){
        if(head1==NULL) return head2;
        if(head2==NULL) return head1;
        Node *head=NULL, *curr=NULL;
        if(head1->data<head2->data){
            head=curr=head1;
            head1=head1->next;
        }
        else{
            head=curr=head2;
            head2=head2->next;
        }
        while(head1 && head2){
            if(head1->data<head2->data){
                curr->next=head1;
                curr=curr->next;
                head1=head1->next;
            }
            else{
                curr->next=head2;
                curr=curr->next;
                head2=head2->next;
            }
        }
        if(head1!=NULL) curr->next=head1;
        else curr->next=head2;
        return head;
    }
  
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if(head==NULL || head->next==NULL) return head;
        Node* slow=head;
        Node* fast=head;
        Node* prev=head;
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        Node *left=mergeSort(head);
        Node *right=mergeSort(slow);
        return merge(left,right);
        return NULL;
    }
};