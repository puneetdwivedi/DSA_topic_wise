// https://leetcode.com/contest/weekly-contest-281/problems/merge-nodes-in-between-zeros/
class Solution {
public:
    pair<ListNode*,int> sumMerge(ListNode *head){
        if(head -> next == NULL) return {NULL,-1};
        int sum = 0;
        ListNode *ptr = head -> next;
        while(ptr -> val != 0){
            sum += ptr -> val;
            ptr = ptr -> next;
        }
        return {ptr, sum};
    }
    ListNode* mergeNodes(ListNode* head) {
        if(head == NULL)return NULL;
        ListNode *ptr = head;
        
        while(ptr -> next  != NULL){
            auto tmp = sumMerge(ptr);
            ptr -> val = tmp.second;
            if(tmp.first -> next == NULL){
                ptr -> next = NULL;
                break;
            }
            
            ptr -> next = tmp.first;
            ptr = ptr -> next;
        }
        return head;
    }
};