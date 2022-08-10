//problem link: https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    if(head==NULL) return;
    if(head->next==NULL){
        *head1_ref=head;
        return;
    }
    Node* slow=head, *fast=head->next, *prev=head;
    while(fast!=head && fast->next!=head){
        slow=slow->next;
        prev=fast->next;
        fast=fast->next->next;
    }
    Node *head2=slow->next;
    slow->next=head;
    *head1_ref=head;
    *head2_ref=head2;
    if(fast->next==head) fast->next=head2;
    else prev->next=head2;
}