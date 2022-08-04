//problem link: https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    Node* curr1=head1, *curr2=head2;
    int n=0, m=0;
    while(curr1!=NULL){
        n++;
        curr1=curr1->next;
    }
    while(curr2!=NULL){
        m++;
        curr2=curr2->next;
    }
    if(n<m) swap(head1,head2);
    curr1=head1;
    curr2=head2;
    int k=abs(n-m);
    while(k-- && curr1!=NULL){
        curr1=curr1->next;
    }
    while(curr1 && curr2 && curr1!=curr2){
        curr1=curr1->next;
        curr2=curr2->next;
    }
    return (curr1) ? curr1->data : -1;
}