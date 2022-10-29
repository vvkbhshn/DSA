//problem link: https://www.interviewbit.com/problems/merge-k-sorted-lists/
 
class comp{
    public:
    bool operator()(ListNode* A, ListNode* B){
        return A->val>B->val;
    }
}; 
 
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    ListNode* head=NULL;
    ListNode* prev=NULL;
    priority_queue<ListNode*,vector<ListNode*>,comp> pq(A.begin(),A.end());
    while(!pq.empty()){
        ListNode* curr=pq.top();
        pq.pop();
        if(prev==NULL) head=curr;
        else prev->next=curr;
        prev=curr;
        if(curr->next!=NULL) pq.push(curr->next);
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