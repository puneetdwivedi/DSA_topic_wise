bool isPalindrome(ListNode* head) {
       string st;
        ListNode* ptr=head;
        while(ptr != NULL){
            st+=(to_string(ptr->val));
            ptr=ptr->next;
        }
        string s=st;
        reverse(st.begin(),st.end());
        if(st == s)return true;
        return false;
    }
    