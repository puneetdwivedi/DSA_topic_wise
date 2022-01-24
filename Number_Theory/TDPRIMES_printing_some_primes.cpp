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
const int n=99998954;
bool sieve[n];
void generatePrime(){
	for(int i=0;i<n;i++){
		sieve[i]=true;
	}
	sieve[0]=sieve[1]=false;
	for(int i=2;i*i<=n;i++){
		if(sieve[i]){
			for(int j=i*i;j<n;j+=i){
				sieve[j]=false;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	puneetMode();

	generatePrime();
	int t=0;
	// cin>>t;t--;
	do{
		int x=0;
		for(int i=2;i<n;i++){
			if(sieve[i]==true)x++;
			if(x%100 ==1 && sieve[i]==true){
				cout<<i<<endl;
			}
		}
	}while(t--);

	return 0;
}