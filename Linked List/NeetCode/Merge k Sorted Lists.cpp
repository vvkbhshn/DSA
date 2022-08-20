//problem link: https://leetcode.com/problems/merge-k-sorted-lists/

class Solution {
public:
    
    ListNode *mergeLists(ListNode *l1, ListNode *l2){
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode *head=NULL;
        ListNode *curr=NULL;
        if(l1->val<l2->val){
            head=curr=l1;
            l1=l1->next;
        }
        else{
            head=curr=l2;
            l2=l2->next;
        }
        while(l1!=NULL && l2!=NULL){
            if(l1->val<l2->val){
                curr->next=l1;
                curr=curr->next;
                l1=l1->next;
            }
            else{
                curr->next=l2;
                curr=curr->next;
                l2=l2->next;
            }
        }
        if(l1!=NULL) curr->next=l1;
        else if(l2!=NULL) curr->next=l2;
        return head;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        int n=lists.size();
        int interval=1;
        while(interval<n){
            for(int i=0;i+interval<n;i+=2*interval){
                lists[i]=mergeLists(lists[i],lists[i+interval]);
            }
            interval*=2;
        }
        return lists[0];
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */