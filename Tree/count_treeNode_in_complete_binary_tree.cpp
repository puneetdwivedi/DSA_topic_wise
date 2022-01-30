// link https://leetcode.com/problems/count-complete-tree-nodes/
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
    int leftHeight(TreeNode* root){
        if(root==NULL)return 0;
        return 1+leftHeight(root->left);
    }
    int rightHeight(TreeNode* root){
        if(root==NULL)return 0;
        return 1+rightHeight(root->right);
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        int lh=leftHeight(root);
        int rh=rightHeight(root);
        if(lh==rh){
            return ((1<<lh)-1);
        }
        else return 1+countNodes(root->left)+countNodes(root->right);
    }
};