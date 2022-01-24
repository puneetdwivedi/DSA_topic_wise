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
		int prefixsum[n];
		prefixsum[0]=arr[0];
		for(int i=1;i<n;i++){
			prefixsum[i]=prefixsum[i-1]+arr[i];
		}
		int q;cin>>q;
		while(q--){
			int x,y;cin>>x>>y;
			if(x==0){
				cout<<prefixsum[y]<<endl;continue;
			}
			cout<<prefixsum[y]-prefixsum[x-1]<<endl;
		}
	}while(t--);

	return 0;
}