// Problem Link: https://leetcode.com/problems/balance-a-binary-search-tree/
/* Puneet Dwivedi */


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
    private:
    int height(TreeNode* node){
        if(node == NULL) return 0;
        int lh = height(node-> left);
        int rh = height(node -> right);
        
        return 1 + max(lh, rh);
    }
    
    int balancefactor(TreeNode* root){
        if(root == NULL) return 0;
        return height(root->left)- height(root-> right);
    }
    
    TreeNode* rightrotation(TreeNode* root){
        TreeNode* x = root;
        TreeNode* y = root -> left;
        TreeNode* t2 = y -> right;
        
        // logic for right rotation
        y -> right = x;
        x -> left = t2;
        return y;
    }
    
    TreeNode* leftrotation(TreeNode* root){
        TreeNode* x = root;
        TreeNode* y = root -> right;
        TreeNode* t2 = y -> left;
        
        // logic for left rotation
        y -> left = x;
        x -> right = t2;
        
        return y;
    }
public:
    TreeNode* balance(TreeNode* root){
        if(root == NULL) return NULL;
        
        root -> left = balance(root -> left);
        root -> right = balance(root -> right);
        
        int bf = balancefactor(root);
        
        // ll rotation 
        if(bf >1 && root-> left -> left != NULL){
            return rightrotation(root);
        }
        // rr rotation
        else if(bf < -1 && root -> right -> right != NULL){
            return leftrotation(root);
        }
        
        else if(bf >1 &&  root-> left -> left == NULL){
            root -> left  = leftrotation(root -> left);
            return rightrotation(root);
        }
        else if(bf < -1 && root-> right -> right == NULL){
            root -> right = rightrotation(root -> right);
            return leftrotation(root);
        }
        
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        return balance(root);
    }
};








// approch 2

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
    void inorder(TreeNode* root, vector<int> &res){
        if(root == NULL) return ;
        inorder(root -> left, res);
        res.push_back(root -> val);
        inorder(root -> right , res);
    }
    
    TreeNode* bst(vector<int> & arr, int low, int high){
        if(low > high) return NULL;
        int mid = (low + high) >> 1;
        TreeNode* root = new TreeNode(arr[mid]);
        root -> left = bst(arr, low, mid-1);
        root -> right = bst(arr, mid+1, high);
        
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(root == NULL) return root;
        vector<int> arr;
        inorder(root, arr);
        
        return bst(arr, 0, arr.size()-1);
    }
};