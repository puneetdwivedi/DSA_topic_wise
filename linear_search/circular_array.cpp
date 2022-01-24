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

void print_in_circular(int arr[],int n,int k){
	for(int i=k;i<n+k;i++){
		cout<<arr[i%n]<<" ";
	}
	cout<<endl;
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
		print_in_circular(arr,n,k-1);

	}while(t--);

	return 0;
}