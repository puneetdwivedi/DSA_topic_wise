/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(root == NULL)return true;
        queue<TreeNode*>q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            if(level % 2 == 0){
                int prv = INT_MIN;
                for(int i = 0; i < n; i++){
                    auto node = q.front();
                    q.pop();
                    if(node -> val % 2 == 0 || node -> val <= prv)return false;
                    prv = node -> val;
                    if(node -> left != NULL) q.push(node -> left);
                    if(node -> right != NULL) q.push(node -> right);
                }
            }
            else{
                int prv = INT_MAX;
                for(int i = 0; i < n; i++){
                    auto node = q.front();
                    q.pop();
                    if(node -> val % 2 == 1 || node -> val >= prv)return false;
                    prv = node -> val;
                    if(node -> left != NULL) q.push(node -> left);
                    if(node -> right != NULL) q.push(node -> right);
                }
                
                
            }
            level++;
        }
        return true;
    }
};