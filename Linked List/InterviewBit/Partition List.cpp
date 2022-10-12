//problem link: https://www.interviewbit.com/problems/partition-list/

ListNode* Solution::partition(ListNode* A, int B) {
    if(A==NULL) return A;
    ListNode *smallerThanB=NULL;
    ListNode *greaterThanB=NULL;
    ListNode *head1=NULL;
    ListNode *head2=NULL;
    ListNode *curr=A;
    while(curr!=NULL){
        if(curr->val<B){
            if(smallerThanB==NULL){
                smallerThanB=curr;
                head1=curr;
            }
            else{
                smallerThanB->next=curr;
                smallerThanB=smallerThanB->next;
            }
            curr=curr->next;
            smallerThanB->next=NULL;            
        }
        else{
            if(greaterThanB==NULL){
                greaterThanB=curr;
                head2=curr;
            }
            else{
                greaterThanB->next=curr;
                greaterThanB=greaterThanB->next;
            }
            curr=curr->next;
            greaterThanB->next=NULL;
        }
    }    
    if(head1!=NULL){
        smallerThanB->next=head2;
        return head1;
    }
    else return head2;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */