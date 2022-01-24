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

bool isperfect_number(int n){
	if(n==1)return false;
	int sum=1;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			if(i == n/i)sum+=i;
			else{
				sum+=i;
				sum+=n/i;
			}
		}
	}
	return (sum==n);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	puneetMode();

	int t=0;
	cin>>t;t--;
	do{
		int n;cin>>n;
		if(isperfect_number(n))cout<<"YES";
		else cout<<"NO";
		cout<<endl;
	}while(t--);

	return 0;
}