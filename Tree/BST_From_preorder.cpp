// Construct Binary Search Tree from Preorder Traversal
// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/


class Solution {
public:
    TreeNode* construct(vector<int> &pre,int psi,int pei,vector<int>& in,int isi,int iei,map<int,int>&mp){
        if(psi >pei || isi>iei )return NULL;
        TreeNode* root=new TreeNode(pre[psi]);
        int inroot=mp[pre[psi]];
        int left_el=inroot-isi;
        root->left=construct(pre,psi+1,psi+left_el,in,isi,inroot-1,mp);
        root->right=construct(pre,psi+left_el+1,pei,in,inroot+1,iei,mp);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       vector<int>inorder=preorder;
        sort(inorder.begin(),inorder.end());
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int n=preorder.size();
        TreeNode* root=construct(preorder,0,n-1,inorder,0,n-1,mp);
        return root;
    }
};

//method 2


class Solution {
public:
    TreeNode* construct(vector<int> &pre,int &i,int ub){
        if(i>=pre.size() || pre[i]> ub)return NULL;
        TreeNode* root=new TreeNode(pre[i]);i++;
        
        root->left=construct(pre,i,root->val);
        root->right=construct(pre,i,ub);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return construct(preorder,i,INT_MAX);
    }
};