
class Solution {
private:
    bool isleaf(Node* root){
        if(root->left ==NULL && root->right==NULL)return true;
        return false;
    }
    void leftboundary(Node* root,vector<int>&ds){
        if(root==NULL)return ;
        if(!isleaf(root)){
            ds.push_back(root->data);
            if(root->left != NULL)leftboundary(root->left,ds);
            else if(root->right != NULL)leftboundary(root->right,ds);
        }
    }    
    void rightboundary(Node*root,vector<int>&ds){
        if(root==NULL)return ;
        if(!isleaf(root)){
            
            if(root->right != NULL){
                rightboundary(root->right,ds);
                ds.push_back(root->data);
            }
            else if(root->left != NULL){
                rightboundary(root->left,ds);
                ds.push_back(root->data);
            }
        }
    }
    void inorder(Node* root, vector<int>&ds){
        if(root==NULL)return ;
        if(isleaf(root)){
            ds.push_back(root->data);
            return ;
        }
        inorder(root->left,ds);
        inorder(root->right,ds);
    }
public:

    vector <int> boundary(Node *root)
    {
        vector<int>res;
        if(root==NULL){
            return res;
        }
        if(root->left==NULL and root->right==NULL){
            res.push_back(root->data);return res;
        }
        
        leftboundary(root,res);
        inorder(root,res);
        rightboundary(root,res);
        res.pop_back();
        return res;
    }
};