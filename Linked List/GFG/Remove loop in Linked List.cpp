//problem link: https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        if(head==NULL) return;
        Node *slow=head, *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }
        if(slow!=fast) return;
        if(slow==head){
            while(fast->next!=slow) fast=fast->next;
        }
        else{
            slow=head;
            while(slow->next!=fast->next){
                slow=slow->next;
                fast=fast->next;
            }
        }
        fast->next=NULL;
    }
};