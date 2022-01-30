/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string st="";
        if(root==NULL)return "";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            // st.append(",")
            if(node==NULL)st.append("N");
            else st.append(to_string(node->val));
            st.push_back(',');
            if(node != NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return st;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)return NULL;
        stringstream st(data);
        string s;
        getline(st,s,',');
        TreeNode* root=new TreeNode(stoi(s));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            getline(st,s,',');
            if(s=="N"){
                node->left=NULL;
            }
            else{
                TreeNode* left=new TreeNode(stoi(s));
                node->left=left;
                q.push(node->left);
            }
            getline(st,s,',');
            if(s=="N"){
                node->right=NULL;
            }
            else{
                TreeNode* right=new TreeNode(stoi(s));
                node->right=right;
                q.push(node->right);
            }
            
        }
        return root;
    }
};