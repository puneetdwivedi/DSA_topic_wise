// problem link : https://leetcode.com/problems/rotate-list/
ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)return head;
        int sz=0;
        ListNode* ptr=head;
        while(ptr != NULL){
            sz++;
            ptr=ptr->next;
        }
        k%=sz;
        if(k==0)return head;
        ListNode* new_head;
        ptr=head; 
        while((sz-k)>1){
            ptr=ptr->next;
            k++;
        }
        new_head=ptr->next;
        ptr->next=NULL;
        ptr=new_head;
        while(ptr->next != NULL){
            ptr=ptr->next;
        }
        ptr->next=head;
        return new_head;
    
        
    }




    // 2nd time

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
    int size(ListNode* head){
        int sz = 0;
        while(head != NULL){
            sz++;
            head = head -> next;
        }
        
        return sz;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL) return head;
        
        int n = size(head);
        k %= n;
        
        ListNode* ptr = head;
        
        for(int i = 1; i <n- k; i++){
            ptr = ptr -> next;
        }
        
        ListNode* new_head = ptr -> next;
        ptr -> next = NULL;
        if(new_head == NULL) return head;
        
        ListNode* ptr1 = new_head;
        while(ptr1 -> next != NULL){
            ptr1 = ptr1 -> next;
        }
        ptr1 -> next = head;
        
        return new_head;
        
        
    }
};