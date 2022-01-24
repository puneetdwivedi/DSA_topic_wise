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
		string st,ws;cin>>st>>ws;
		unordered_map<char,int>mp;
		int n1=st.length();
		int n2=ws.length();
		loop(i,0,n2){
			mp[ws[i]]++;
		}
		
		int count=mp.size();
		for(int i=0;i<n2;i++){
			if(mp.find(st[i]) != mp.end()){
				mp[st[i]]--;
				if(mp[st[i]]==0)count--;
			}
		}
		int res=0;
		if(count==0)res++;
		int i=1;
		while(i<=n1-n2){
			if(mp.find(st[i-1]) != mp.end()){
				mp[st[i-1]]++;
				if(mp[st[i-1]] ==1)count++;
			}
			if(mp.find(st[i+n2-1]) != mp.end()){
				mp[st[i+n2-1]]--;
				if(mp[st[i+n2-1]] ==0)count--;

			}
			if(count==0){
				res++;
			}
			i++;
		}
		cout<<res;
	}while(t--);

	return 0;
}