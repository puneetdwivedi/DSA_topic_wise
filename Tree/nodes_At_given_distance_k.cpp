// Problem Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void level(TreeNode* root, map<TreeNode*,TreeNode*> &parent){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left != NULL){
                parent[node->left]=node;
                q.push(node->left);
            }
            if(node->right != NULL){
                parent[node->right]=node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>res;
        if(root==NULL)return res;
        map<TreeNode*,TreeNode*>parent; 
        parent[root]=NULL;
        level(root,parent);
        map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        int curr=0;
        while(!q.empty()){
            int n=q.size();
            if(curr>=k)break;
            else curr++;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left != NULL && visited.find(node->left) ==visited.end()){
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right != NULL && visited.find(node->right)==visited.end()){
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(parent[node] != NULL && visited.find(parent[node])==visited.end()){
                    q.push(parent[node]);
                    visited[parent[node]]=true;
                }
            }
        }
        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};