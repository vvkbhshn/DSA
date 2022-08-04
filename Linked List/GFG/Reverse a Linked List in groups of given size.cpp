//problem link: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if(head==NULL) return NULL;
        node* curr=head;
        node *prev=NULL;
        node *next=NULL;
        int cnt=k;
        while(cnt-- && curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head->next=reverse(next,k);
        return prev;
    }
};