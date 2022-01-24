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
int largest_sequence(int arr[],int n){
	unordered_set<int>us;
	for(int i=0;i<n;i++)us.insert(arr[i]);
	int ans=0;
	for(int i=0;i<n;i++){
		if(us.find(arr[i]-1) == us.end()){
			int j=arr[i];
			while(us.find(j) != us.end())j++;
			ans=max(ans,j-arr[i]);
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	puneetMode();

	int t=0;
	// cin>>t;t--;
	do{
		int n;cin>>n;
		int arr[n];
		loop(i,0,n)cin>>arr[i];
		cout<<largest_sequence(arr,n);
	}while(t--);

	return 0;
}