//problem link: https://practice.geeksforgeeks.org/problems/circular-linked-list/1

/* Should return true if linked list is circular, else false */
bool isCircular(Node *head)
{
   // Your code here
   if(head==NULL) return false;
   Node* curr=head->next;
   while(curr){
       if(curr==head) return true;
       curr=curr->next;
   }
   return false;
}