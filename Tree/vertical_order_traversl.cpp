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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL)return res;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        map<int,map<int,multiset<int>>>mp;
        while(!q.empty()){
            auto tmp=q.front();
            TreeNode* node=tmp.first;
            int v=tmp.second.first;
            int l=tmp.second.second;
            q.pop();
            mp[v][l].insert(node->val);
            if(node->left != NULL){
                pair<int,int>p=make_pair(v-1,l+1);
                q.push(make_pair(node->left,p));
            }
            if(node->right != NULL){
                q.push({node->right,{v+1,l+1}});
            }
        }
        for(auto p:mp){
            vector<int>vertical;
            for(auto z:p.second){
                vertical.insert(vertical.end(),z.second.begin(),z.second.end());
            }
            res.push_back(vertical);
        }
        return res;
    }
};