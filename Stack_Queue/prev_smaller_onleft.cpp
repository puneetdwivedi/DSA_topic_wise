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

vector<int> prev_greater_element(int arr[],int n){
	vector<int>res(n);
	stack<int>st;
	int i=0;
	while(i<n){
		if(st.empty()){
			res[i]=-1;
			st.push(arr[i++]);
		}
		else if(st.top()<arr[i]){
			res[i]=st.top();
			st.push(arr[i++]);
		}
		else st.pop();
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
		int arr[n];
		loop(i,0,n)cin>>arr[i];
		vector<int>res=prev_greater_element(arr,n);
		loop(i,0,n)cout<<res[i]<<" ";
		cout<<endl;
	}while(t--);

	return 0;
}