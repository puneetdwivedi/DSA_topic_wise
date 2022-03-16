// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
   map<Node*, Node*> findparent(Node* root, Node* &tgt,int target){
       map<Node*,Node*> parent;
       parent[root] = NULL;
       queue<Node*> q;
       q.push(root);
       while(!q.empty()){
           auto node = q.front();
           q.pop();
           if(node -> data == target)  tgt = node;
           if(node -> left != NULL){
               parent[node -> left] = node;
               q.push(node -> left);
           }
           if(node -> right != NULL){
               parent[node -> right] = node;
               q.push(node -> right);
           }
       }
       
       return parent;
   }
    int minTime(Node* root, int target) 
    {
        // if(node == NULL) return 0;
        Node* tgt = NULL;
        map<Node*,Node*> parent = findparent(root,tgt,target);
        
        map<Node*,bool> visited;
        
        queue<Node*> q;
        q.push(tgt);
        visited[tgt] = true;
        
        int res = 0;
        
        while(!q.empty()){
            int n = q.size();
            res++;
            
            for(int i = 0; i<n; i++){
                auto node = q.front();
                q.pop();
                
                if(node -> left != NULL && visited[node ->left] == false){
                    visited[node -> left] =true;
                    q.push(node -> left);
                }
                if(node -> right != NULL && visited[node -> right] == false){
                    visited[node -> right] = true; 
                    q.push(node -> right);
                }
                if(parent[node] != NULL && visited[parent[node]] == false){
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
        }
    
          return res-1;
          
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends