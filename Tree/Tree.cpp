// Problem Link: 
/* Puneet Dwivedi */

#include<bits/stdc++.h>
using namespace std;
#define loop(i,l,h) for(int i=l;i<h;i++)
#define logarr(arr,a,b)	for(int z=(a);z<(b);z++) cout<<(arr[z])<<" ";cout<<endl;
#define endl "\n"
#define mod  1000000007
typedef long long int ll;
typedef long double ld;
#define gs 5
void file_input_output(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE
}

/* ***************************************************** */
template <typename T>
class TreeNode{
public:
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(){
		this->left=NULL;
		this->right=NULL;
	}
	TreeNode(int val){
		this->data=val;
		this->left=NULL;
		this->right=NULL;
	}
};

TreeNode<int>* construct_binary_tree(TreeNode<int>*root ,int n ,int arr[]){
	queue<TreeNode<int>*>q;
	for(int i=0;i<n;i++){
		TreeNode<int>* toadd=new TreeNode<int>(arr[i]);
		if(root==NULL){
			root=toadd;
		}
		else if(q.front()->left == NULL){
			q.front()->left=toadd;
		}
		else{
			q.front()->right=toadd;
			q.pop();
		}
		if(toadd->data != -1)q.push(toadd);
	}
	return root;
}

void preorder(TreeNode<int>* node){
   	if(node == NULL)return ;
	if(node->data != -1)cout<<node->data<<" ";
   	preorder(node->left);
 	preorder(node->right);
}
void postorder(TreeNode<int>*node){
	if(node==NULL)return ;
	postorder(node->left);
	postorder(node->right);
	if(node->data != -1)cout<<node->data<<" ";
	
}
void inorder(TreeNode<int>*node){
	if(node==NULL)return ;
	inorder(node->left);
	if(node->data != -1)cout<<node->data<<" ";
	inorder(node->right);
}


void printtreein2d(TreeNode<int>* r,int space){
    if(r== NULL)return ;
    space+=gs;
    printtreein2d(r->right,space);
    cout<<endl;
    for(int i=gs;i<=space;i++)cout<<" ";
   	if(r->data != -1) cout<<r->data<<endl;
    printtreein2d(r->left,space);
}

int main(){
	clock_t begin=clock();
	file_input_output();


	int t=0;
	// cin>>t;t--;
	do{
		int n;cin>>n;

		int arr[n];
		loop(i,0,n){
			cin>>arr[i];
		}
		TreeNode<int>*root=NULL;
		root=construct_binary_tree(root,n,arr);
		// printtreein2d(root,5);
		preorder(root);
		
	}while(t--);



	#ifndef ONLINE_JUDGE
		clock_t end=clock();
		cout<<"\n\nFinished in "<<double(end-begin)/CLOCKS_PER_SEC*1000<<" ms";
	#endif 

	return 0;
}