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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)return l2;
        else if(l2 == NULL)return l1;
        
        ListNode* head = NULL;
        if(l1 -> val  > l2 -> val){
            head = l2;
            l2 = l2 -> next;
        } 
        else{
            head = l1;
            l1 = l1 -> next;
        } 
        ListNode* curr = head;
        
        while(l1 != NULL && l2 != NULL){
            if(l1 -> val  > l2 -> val) {
                curr -> next = l2;
                curr = l2;
                l2 = l2 ->next;
            }
            else{
                curr -> next = l1;
                curr = l1;
                l1 = l1 -> next;
            }
        }
        curr -> next = (l1 == NULL) ? l2 : l1;
        return head;
    }    
};