//problem link: https://www.interviewbit.com/problems/insertion-sort-list/

ListNode* Solution::insertionSortList(ListNode* A) {
    if(A==NULL || A->next==NULL) return A;
    ListNode *head=new ListNode(-1);
    head->next=A;
    ListNode *prev=A, *curr=A->next;
    while(curr!=NULL){
        ListNode* next=curr->next;
        if(curr->val<prev->val){
            prev->next=next;
            ListNode *currNode=head->next, *prevNode=head;
            while(currNode!=next){
                if(currNode->val>curr->val){
                    prevNode->next=curr;
                    curr->next=currNode;
                    break;
                }
                prevNode=currNode;
                currNode=currNode->next;
            }
        }
        else prev=curr;
        curr=next;
    }
    ListNode* temp=head;
    head=head->next;
    delete (temp);
    return head;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */