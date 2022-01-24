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

bool isprime(int n){
	if(n==1)return false;
	if(n==2)return true;
	for(int i=2;i*i<=n;i++){
		if(n%i==0)return false;
	}
	return true;
}
int sumofdigit(int n){
	int sum=0;
	while(n>0){
		sum+=n%10;
		n/=10;
	}
	return sum;
}
int arr[1000000+1];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	puneetMode();

	int t=0;
	// cin>>t;t--;
	do{
		
		arr[0]=0;
		for(int i=1;i<=1000000;i++){
			arr[i]=arr[i-1];
			if(isprime(i) && isprime(sumofdigit(i)))arr[i]++;
		}
		int q;cin>>q;
		while(q--){
			int x,y;cin>>x>>y;
			cout<<arr[y]-arr[x-1]<<endl;
		}

	}while(t--);

	return 0;
}