// Problem Link: https://leetcode.com/problems/add-two-numbers/



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
    int size(ListNode* head){
        int sz = 0;
        while(head != NULL){
            sz++;
            head = head -> next;
        }
        
        return sz;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        else if(l2 == NULL) return l1;
        
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        
        if(size(l1) < size(l2)){
            ptr2 = l1;
            ptr1 = l2;
        }
        
        int carry = 0;
        while(ptr1-> next != NULL && ptr2 != NULL){
            ptr1 -> val += (carry + ptr2 -> val);
            carry = ptr1 -> val / 10;
            ptr1 -> val %= 10;
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }
        
        if(ptr1 -> next == NULL && ptr2 != NULL){
             ptr1 -> val += (carry + ptr2 -> val);
            carry = ptr1 -> val / 10;
            ptr1 -> val %= 10; 
        }
        if(ptr2 == NULL){
             while(ptr1 != NULL && ptr1 -> next != NULL){
                ptr1 -> val += carry;
                carry = ptr1 -> val / 10;
                ptr1 -> val %= 10;
                ptr1 = ptr1 -> next;
            }
            ptr1 -> val += carry;
            carry = ptr1 -> val / 10;
            ptr1 -> val %= 10;
        }
       
        
        if(carry != 0){
            ptr1 -> next = new ListNode(carry);
        }
        
        if(size(l1) >= size(l2)) return l1;
        return l2;
        
        
        
    }
};