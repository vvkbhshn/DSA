//problem link: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {        
        Node *curr=head;
        while(curr!=NULL){
            Node* next=curr->next;
            if(curr->child!=NULL){
                Node *currNode=curr;
                flatten(curr->child);
                for(Node *temp=curr->child;temp!=NULL;temp=temp->next){
                    curr->next=temp;
                    temp->prev=curr;
                    curr=curr->next;
                }  
                curr->next=next;
                if(next!=NULL) next->prev=curr;
                currNode->child=NULL;
            }
            curr=next;            
        }
        return head;
    }
};