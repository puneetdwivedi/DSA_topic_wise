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
vector<int> first_negative(int arr[],int n,int k){
	queue<int> q;
	for(int i=0;i<k;i++){
		if(arr[i]<0)q.push(i);
	}
	vector<int>res;
	if(q.empty())res.push_back(0);
	else res.push_back(arr[q.front()]);
	for(int i=1;i<=n-k;i++){
		if(arr[i+k-1] <0)q.push(i+k-1);
		if(q.front()==i-1){
			q.pop();
		}
		if(q.empty())res.push_back(0);
		else res.push_back(arr[q.front()]);
	}
	return res;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	puneetMode();

	int t=0;
	// cin>>t;t--;
	do{
		int n,k;cin>>n>>k;
		int arr[n];
		loop(i,0,n)cin>>arr[i];
		vector<int>res=first_negative(arr,n,k);
		loop(i,0,res.size())cout<<res[i]<<" ";
	}while(t--);

	return 0;
}