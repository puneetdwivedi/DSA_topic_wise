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
	cin>>t;t--;
	do{
		int n;cin>>n;
		ll arr[n];
		loop(i,0,n)cin>>arr[i];
		if(arr[0]== -1){
			arr[0]=0;
		}
		ll prefixsum=arr[0];
		for(int i=1;i<n;i++){
			if(arr[i]==-1){
				arr[i]=prefixsum/i;
			}
			prefixsum+=arr[i];
		}
		loop(i,0,n)cout<<arr[i]<<" ";
		cout<<endl;
	}while(t--);

	return 0;
}