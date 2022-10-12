//problem link: https://www.interviewbit.com/problems/add-two-numbers-as-lists/

ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode *head=NULL;
    ListNode *curr=NULL;
    int carry=0;
    while(A!=NULL || B!=NULL || carry>0){
        int sum=carry;
        if(A!=NULL) sum+=A->val, A=A->next;
        if(B!=NULL) sum+=B->val, B=B->next;
        carry=sum/10;
        sum=sum%10;
        ListNode *newNode=new ListNode(sum);
        if(curr==NULL) head=curr=newNode;
        else{
            curr->next=newNode;
            curr=curr->next;
        }
    }
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