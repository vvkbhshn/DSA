//problem link: https://www.interviewbit.com/problems/copy-list/

RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    if(A==NULL) return NULL;
    RandomListNode* curr=A;
    while(curr!=NULL){
        RandomListNode* nextNode=curr->next;
        RandomListNode* newNode=new RandomListNode(curr->label);
        curr->next=newNode;
        newNode->next=nextNode;
        curr=nextNode;
    }
    curr=A;
    while(curr!=NULL){
        RandomListNode* nextNode=curr->next->next;
        if(curr->random!=NULL) curr->next->random=curr->random->next;
        curr=nextNode;
    }
    RandomListNode* head=A->next;
    RandomListNode* p1=A, *p2=A->next;
    while(p1!=NULL){
        p1->next=p1->next->next;
        if(p2->next!=NULL) p2->next=p2->next->next;
        p1=p1->next;
        p2=p2->next;
    }
    return head;
}

/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */