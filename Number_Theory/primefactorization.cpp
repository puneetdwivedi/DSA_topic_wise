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
const int n=1e6;
int spf[n];
void create_sieve(){
	for(int i=0;i<=n;i++){
		spf[i]=i;
	}
	for(int i=2;i*i<=n;i++){
		if(spf[i]==i){
			for(int j=i*i;j<=n;j+=i){
				if(spf[j]==j){
					spf[j]=i;
				}
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	puneetMode();

	int t=0;
	// cin>>t;t--;
	create_sieve();
	do{
		int n;cin>>n;
		while(n != 1){
			cout<<spf[n]<<" ";
			n/=spf[n];
		}
		cout<<endl;
	}while(t--);

	return 0;
}