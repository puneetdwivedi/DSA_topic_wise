

/**
 * link :https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 * 
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
    TreeNode* construct(vector<int>& pre,int psi,int pei,vector<int>& in,int isi,int iei,map<int,int>&mp){
        if(psi>pei || isi>iei)return NULL;
        TreeNode* root=new TreeNode(pre[psi]);
        int inroot=mp[pre[psi]];
        int num_left=inroot-isi;
        root->left=construct(pre,psi+1,psi+num_left,in,isi,inroot-1,mp);
        root->right=construct(pre,psi+num_left+1,pei,in,inroot+1,iei,mp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root=construct(preorder,0,n-1,inorder,0,n-1,mp);
        return root;
    }
};