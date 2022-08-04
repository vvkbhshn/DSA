//problem link: https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1

Node *removeDuplicates(Node *head)
{
    if(head==NULL) return NULL;
    Node *curr=head;
    while(curr->next!=NULL){
        if(curr->data==curr->next->data){
            Node *temp=curr->next;
            curr->next=curr->next->next;
            delete temp;
        }
        else curr=curr->next;
    }
    return head;
}