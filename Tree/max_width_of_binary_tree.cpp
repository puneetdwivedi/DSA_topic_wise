// link => https://leetcode.com/problems/maximum-width-of-binary-tree/

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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int res=0;
        while(!q.empty()){
            int n=q.size();
            int midx=q.front().second;
            int f,l;
            for(int i=0;i<n;i++){
                auto tp=q.front();
                q.pop();
                TreeNode* node=tp.first;
                int idx=tp.second-midx;
                if(i==0)f=idx;
                if(i==n-1)l=idx;
                if(node->left != NULL){
                    q.push({node->left,(2*idx+1)});
                }
                if(node->right != NULL){
                    q.push({node->right,(2*idx+2)});
                }
            }
            res=max(res,(l-f+1));
        }
        return res;
    }
};