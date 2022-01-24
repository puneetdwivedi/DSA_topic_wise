// problem_link : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz=0;
        ListNode* ptr=head;
        while(ptr != NULL){
            sz++;
            ptr=ptr->next;
        }
        if(sz==1)return NULL;
        if(sz == n){
            return head->next;
        }
        ptr=head;
        while((sz-n)>1){
            ptr=ptr->next;
            n++;
        }
        ptr->next=ptr->next->next;
        return head;
    }
};