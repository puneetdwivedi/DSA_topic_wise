// https://leetcode.com/problems/validate-binary-search-tree/



class Solution {
public:
    bool check(TreeNode* root,long long l,long long r){
        if(root==NULL)return true;
        if(!(root->val > l && root->val < r))return false;
        bool left=check(root->left,l,root->val);
        bool right=check(root->right,root->val,r);
        if(left &&right)return true;
        return false;
        
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)return true;
        return (check(root->left,LLONG_MIN,root->val) && check(root->right,root->val,LLONG_MAX));
    }
};