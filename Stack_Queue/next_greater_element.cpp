#include<bits/stdc++.h>
using namespace std;
#define loop(i,l,h) for(int i=l;i<h;i++)
#define endl "\n"
typedef long long int ll;
typedef long double ld;


inline void puneetMode() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE
}
/* ***************************************************** */

// variation 1
vector<int> next_Greater_on_right(vector<int> arr){
	int n=arr.size();
	vector<int>res(n);
	stack<int>st;
	int i=n-1;
	while(i>=0){
		if(st.empty()){
			res[i]=-1;
			st.push(arr[i]);i--;
		}
		else if(st.top()>arr[i]){
			res[i]=st.top();
			st.push(arr[i]);i--;
		}
		else{
			st.pop();
		}
	}
	return res;
}


// variation 2

vector<int> next_Greater_on_circular_array(vector<int> arr){
	int n=arr.size();
	vector<int>res(n);
	stack<int>st;
	int i=(2*n)-1;
	while(i>=0){
		if(st.empty()){
			res[i%n]=-1;
			st.push(arr[i%n]);i--;
		}
		else if(st.top()>arr[i%n]){
			res[i%n]=st.top();
			st.push(arr[i%n]);i--;
		}
		else{
			st.pop();
		}
	}
	return res;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	puneetMode();

	int t=0;
	cin>>t;t--;
	do{
		int n;cin>>n;
		vector<int>arr(n);
		loop(i,0,n){
			cin>>arr[i];
		}
		vector<int>res;
		res=next_Greater_on_circular_array(arr);
		for(int i=0;i<n;i++){
			cout<<res[i]<<" ";
		}
	}while(t--);

	return 0;
}