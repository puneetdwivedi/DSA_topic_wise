/**
 * https://leetcode.com/problems/recover-binary-search-tree/
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

// nlogn

class Solution {
public:
    void inorder(TreeNode* root,vector<int>& in){
        if(root==NULL)return ;
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    void helper(TreeNode* root,vector<int>& in,int &i){
        if(root ==NULL || i>= in.size())return ;
        helper(root->left,in,i);
        if(root->val != in[i]){
            root->val=in[i];
        }
        i++;
        helper(root->right,in,i);
    }
    void recoverTree(TreeNode* root) {
        vector<int>in;
        inorder(root,in);
        sort(in.begin(),in.end());
        int i=0;
        helper(root,in,i);
    }
};

//o(n)


class Solution {
    TreeNode* prv=NULL;
    TreeNode* first=NULL;
    TreeNode* middle=NULL;
    TreeNode* last=NULL;
public:
    void inorder(TreeNode* root){
        if(root==NULL)return ;
        inorder(root->left);
        if(prv != NULL){
            if(prv->val > root->val && first==NULL){
                first=prv;
                middle=root;
            }
            else if(prv->val > root->val){
                last=root;
            }
        }
        prv=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        if(root==NULL)return ;
        inorder(root);
        if(last ==NULL){
            swap(first->val,middle->val);
        }
        else {
            swap(first->val,last->val);
        }
    }
};