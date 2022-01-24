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
		unordered_map<string,int>mp;
		for(int i=0;i<n;i++){
			string st;cin>>st;
			if(mp.find(st) == mp.end()){
				mp[st]=1;
				cout<<"OK"<<endl;
			}
			else{
				cout<<st+to_string(mp[st])<<endl;
				mp[st]++;
			}

		}
		// cout<<endl;

	}while(t--);

	return 0;
}