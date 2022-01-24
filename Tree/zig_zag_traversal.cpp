
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root==NULL)return result;
        queue<TreeNode*>q;
        q.push(root);
        bool lefttoright=true;
        while(!q.empty()){
            int n=q.size();
            vector<int>v(n);
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                
                int ind=(lefttoright)?i:n-1-i;
                v[ind]=node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            lefttoright=!lefttoright;
            result.push_back(v);
        }
        return result;
    }
};