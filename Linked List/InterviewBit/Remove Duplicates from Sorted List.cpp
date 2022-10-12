//problem link: https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/

ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A==NULL || A->next==NULL) return A;
    ListNode *curr=A;
    while(curr!=NULL){
        if(curr->next!=NULL && curr->next->val==curr->val){
            ListNode *temp=curr->next;
            while(temp!=NULL && temp->val==curr->val){
                ListNode *dupNode=temp;
                temp=temp->next;
                delete dupNode;
            }
            curr->next=temp;
        }
        curr=curr->next;
    }
    return A;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */