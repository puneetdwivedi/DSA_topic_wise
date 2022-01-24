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

bool checkPrime(int n){
	if(n==0 || n==1)return false;
	if(n==2)return true;
	for(int i=2;i*i<=n;i++){
		if(n%i ==0)return false;
	}
	return true;
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
		if(checkPrime(n))cout<<"Yes";
		else cout<<"No";
	}while(t--);

	return 0;
}