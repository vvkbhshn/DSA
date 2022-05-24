//problem link: https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node *curr=head;
        while(curr!=NULL){
            Node *temp=curr->next;
            Node *newNode=new Node(curr->val);
            curr->next=newNode;
            newNode->next=temp;
            curr=temp;
        }

        curr=head;
        while(curr!=NULL){
            if(curr->random!=NULL) curr->next->random=curr->random->next;
            curr=curr->next->next;
        }

        curr=head;
        Node *newHead=head->next;
        Node *copy=newHead;
        while(copy->next!=NULL){
            curr->next=curr->next->next;
            curr=curr->next;
            copy->next=copy->next->next;
            copy=copy->next;
        }
        curr->next=NULL;
        return newHead;        
    }
};