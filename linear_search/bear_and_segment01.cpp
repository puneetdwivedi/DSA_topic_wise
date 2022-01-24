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
		string st;cin>>st;
		int window=0;
		loop(i,0,st.length()){
			if(st[i]=='1')window++;
		}
		if(window ==0){
			cout<<"NO"<<endl;
			continue;
		}
		string rs="";
		bool res=false;
		loop(i,0,window)rs.push_back('1');
		loop(i,0,st.length()-window +1){
			if(st.substr(i,window)==rs){
				res=true;break;
			}
		}
		if(res)cout<<"YES";
		else cout<<"NO";
		cout<<endl;
	}while(t--);

	return 0;
}