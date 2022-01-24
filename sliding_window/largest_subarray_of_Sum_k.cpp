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
		int n,k;cin>>n>>k;
		int arr[n];
		loop(i,0,n)cin>>arr[i];
		int i=0,j=1;
		int sum=arr[0];
		int res=0;
		while(j<n || i<n){
			if(sum==k){
				res=max(res,abs(j-i));
				if(j<n)sum+=arr[j++];
				else break;
			}
			else if(sum>k){
				sum-=arr[i++];
			}
			else{
				sum+=arr[j++];
			}
		}
		cout<<res<<endl;
	}while(t--);

	return 0;
}