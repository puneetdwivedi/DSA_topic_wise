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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head  == NULL || head -> next == NULL) return head;
        
        map<int,int> mp;
        ListNode* ptr = head;
        while(ptr != NULL){
            mp[ptr->val]++;
            ptr = ptr -> next;
        }
        ptr = NULL;
        for(auto it : mp){
            if(it.second == 1){
                if(ptr == NULL) ptr = head;
                else ptr = ptr->next;
                ptr -> val = it.first;
            }
        }
        if(ptr == NULL) return NULL;
        ptr -> next = NULL;
        return head;
    }
};


/// constant space approch


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head  == NULL || head -> next == NULL) return head;
        
        ListNode* dummy= new ListNode(0);
        ListNode* p = dummy;
        ListNode* ptr = head -> next, *prv = head;
        
        while(ptr != NULL){
            if(ptr-> val == prv->val){
                ptr = ptr -> next;
            }
            else {
                if(prv -> next == ptr){
                    p -> next = prv;
                    p = p -> next;
                    p -> next = NULL;
                    prv = ptr;
                    ptr = prv -> next ;
                }
                else{
                    prv = ptr;
                    ptr = prv -> next;
                }
            }
        }
        
        if(prv-> next == ptr){
            p -> next = prv;
        }
        return dummy -> next;
    }
};