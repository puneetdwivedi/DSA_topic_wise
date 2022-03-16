/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i< n-1; i++){
                auto node = q.front();
                q.pop();
                node -> next = q.front();
                if(node -> left != NULL){
                    q.push(node -> left);
                }
                if(node ->right != NULL){
                    q.push(node -> right);
                }
            }
            auto node = q.front();
            q.pop();
            node -> next = NULL;
            if(node -> left != NULL){
                q.push(node -> left);
            }
            if(node ->right != NULL){
                q.push(node -> right);
            }
        }
        return root;
    }
};