//problem link: https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1

class Solution
{
    public:
    Node * removeDuplicates( Node *head) 
    {
        if(head==NULL) return NULL;
        unordered_set<int> vis;
        Node *curr=head;
        while(curr->next!=NULL){
            vis.insert(curr->data);
            if(vis.find(curr->next->data)!=vis.end()){
                Node *temp=curr->next;
                curr->next=curr->next->next;
                delete temp;
            }
            else curr=curr->next;
        }
        return head;
    }
};