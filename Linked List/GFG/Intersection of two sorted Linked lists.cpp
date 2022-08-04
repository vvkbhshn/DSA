//problem link: https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1

Node* findIntersection(Node* head1, Node* head2)
{
    Node *head=NULL, *prev=NULL;
    while(head1!=NULL && head2!=NULL){
        if(head1->data==head2->data){
            Node* temp=new Node(head1->data);
            if(head==NULL) head=prev=temp;
            else{
                prev->next=temp;
                prev=prev->next;
            }
            head1=head1->next;
            head2=head2->next;
        }
        else if(head1->data<head2->data) head1=head1->next;
        else head2=head2->next;
    }
    return head;
}