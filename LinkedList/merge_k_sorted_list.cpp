class Solution {
private:
    ListNode* mrege(ListNode* l1, ListNode* l2){
        if(l1 == NULL) return l2;
        else if(l2 == NULL) return l1;
        ListNode* head;
        if(l1 -> val > l2 -> val){
            head = l2;
            l2 = l2 -> next;
        }
        else {
            head = l1;
            l1 = l1 -> next;
        }
        ListNode* curr = head;
        
        while(l1 != NULL && l2 != NULL){
            if(l1 -> val > l2 -> val){
                curr -> next = l2;
                curr = l2;
                l2 = l2 -> next;
            }
            else{
                curr -> next = l1;
                curr = l1;
                l1 = l1 -> next;
            }
        }
        if(l1 == NULL) curr -> next = l2;
        if(l2 == NULL) curr -> next = l1;
        
        return head;
    }    
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       ListNode* head = NULL;
        for(int i = 0; i < lists.size(); i++){
            head = mrege(head, lists[i]);
        }
        
        return head;
    }
};