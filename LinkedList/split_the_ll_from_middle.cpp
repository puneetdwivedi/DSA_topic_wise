pair<ListNode*, ListNode*> split(ListNode* head){
        if(head == NULL)return {NULL,NULL};
        else if(head -> next == NULL) return {head, NULL};
        ListNode* slow = head;
        ListNode* fast = head -> next;
        ListNode* prv = slow;
        while(fast != NULL && fast->next != NULL){
            slow = slow ->next;
            fast = fast -> next ->next;
        }
        prv = slow -> next;
        slow -> next = NULL;
        return {head, prv};
    }