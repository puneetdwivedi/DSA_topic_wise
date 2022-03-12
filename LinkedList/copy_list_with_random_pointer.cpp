// Problem Link: https://leetcode.com/problems/copy-list-with-random-pointer/




/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node* ptr = head;
        Node* new_head = new Node(0);
        Node* curr = new_head;
        map<Node*, Node*> mp;
        
        while(ptr != NULL){
            Node* toadd = new Node(ptr -> val);
            mp[ptr] = toadd;
            curr -> next = toadd;
            curr = curr -> next;
            ptr = ptr -> next;
        }
        
        ptr = head;
        curr = new_head -> next;
        
        while(ptr != NULL){
            curr -> random = mp[ptr -> random];
            curr = curr -> next;
            ptr = ptr -> next;
        }
        return new_head -> next;
    }
};



// constant space approch


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       Node* ptr1 = head;
     Node* ptr2 = head;
        
        // creating copy next after the node
        while(ptr1 != NULL){
            ptr2 = ptr2 -> next;
            ptr1 -> next = new Node(ptr1 -> val);
            ptr1 = ptr1 -> next;
            ptr1 -> next = ptr2;
            ptr1 = ptr1 -> next;
        }
        ptr1 = head;
        
        // pointing the random pointer
        while(ptr1 != NULL){
            if(ptr1 -> random != NULL){
                ptr1-> next -> random = ptr1 -> random -> next;
            }
            ptr1 = ptr1 -> next -> next;
        }
        
        
        // taking out the copied list
        
        ptr1 = head;
        ptr2 = head;
        Node* new_head = new Node(0);
        Node* cpy = new_head;
        while(ptr1 != NULL){
            ptr2 = ptr2 -> next -> next;
            cpy -> next = ptr1 ->next;
            cpy = cpy -> next;
            ptr1 -> next = ptr2;
            ptr1 = ptr1 -> next;
            
        }
        return new_head -> next;
    }
};