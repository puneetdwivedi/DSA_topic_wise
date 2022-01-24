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

const int n=1000000;
int phi[n+1];
void generate_phi(){
	for(int i=0;i<=n;i++){
		phi[i]=i;
	}
	for(int i=2;i*i<=n;i++){
		if(phi[i]==i){
			for(int j=i;j<=n;j+=i){
				phi[j]/=i;
				phi[j]*=(i-1);
			}
		}
	}

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	puneetMode();
	generate_phi();

	int t=0;
	cin>>t;t--;
	do{
		int x;cin>>x;
		cout<<phi[x];
	}while(t--);

	return 0;
}