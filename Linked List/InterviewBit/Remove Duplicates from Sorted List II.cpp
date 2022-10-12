//problem link: https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/
 
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A==NULL || A->next==NULL) return A;    
    ListNode *head=new ListNode(0);
    head->next=A;
    ListNode *prev=head;
    ListNode *curr=A;
    while(curr!=NULL){
        if(curr->next!=NULL && curr->val==curr->next->val){
            int value=curr->val;
            while(curr!=NULL && curr->val==value){
                ListNode *temp=curr;
                curr=curr->next;
                delete temp;
            }
        }
        else {
            prev->next=curr;
            prev=curr;
            if(curr!=NULL) curr=curr->next;
        }
    }
    prev->next=NULL;
    curr=head;
    head=head->next;
    delete curr;
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