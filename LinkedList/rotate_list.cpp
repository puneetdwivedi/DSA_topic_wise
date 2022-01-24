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