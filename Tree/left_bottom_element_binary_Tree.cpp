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
private:
    void helper(TreeNode* root,int level,pair<int,int>&res){
        if(root==NULL)return ;
        if(res.first <level){
            res.first=level;
            res.second=root->val;
        }
        
        helper(root->left,level+1,res);
        helper(root->right,level+1,res);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
       if(root ==NULL)return -1;
        pair<int,int>res;
        res.first=0;res.second=root->val;
        helper(root,0,res);
        return res.second;
        
    }
};