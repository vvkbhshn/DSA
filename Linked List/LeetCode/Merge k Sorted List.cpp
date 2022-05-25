//problem link: https://leetcode.com/problems/merge-k-sorted-lists/

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

class Solution {
public:   
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if(l1==NULL) return l2;
        else if(l2==NULL) return l1;
        else if(l1->val<l2->val){
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }
        else{
            l2->next=mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        
        
        //Method-1: [Divide and Conquer, Time complexity: O(N*KlogK)]
        if (lists.size() == 0) return nullptr;
        int count = lists.size(), interval = 1;
        while (interval < count) {
            for (int i = 0; i < count - interval; i += interval *2)
                lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
            interval = interval * 2;
        }
        return lists[0];
        
        
        //Method-2 [Naive, Time complexity: O(N*(K^2))]
        // for(int i=1;i<lists.size();i++){
        //     lists[0]=mergeTwoLists(lists[0],lists[i]);
        // }
        // return lists[0];
    }
};