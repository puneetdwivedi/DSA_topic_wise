/**
 * link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    TreeNode* construct(vector<int>& post,int psi,int pei,vector<int>&in,int isi,int iei,map<int,int>&mp){
        if(psi<pei || isi>iei)return NULL;
        TreeNode* root=new TreeNode(post[psi]);
        int inroot=mp[post[psi]];
        int num_right=iei-inroot;
        root->left=construct(post,psi-num_right-1,pei,in,isi,inroot-1,mp);
        root->right=construct(post,psi-1,psi-num_right,in,inroot+1,iei,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mp;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root=construct(postorder,n-1,0,inorder,0,n-1,mp);
        return root;
    }
};