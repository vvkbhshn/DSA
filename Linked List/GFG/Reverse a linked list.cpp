//problem link: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1

class Solution
{
    private:
    Node* prev=NULL;

    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        //Method-1: Iterative
        Node *curr=head;
        while(curr!=NULL){
            Node *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
        
        //Method-2: Recursive
        // if(head==NULL) return prev;
        // Node* next=head->next;
        // head->next=prev;
        // prev=head;
        // return reverseList(next);
    }    
};