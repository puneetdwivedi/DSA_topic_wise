// solution for ax+by=g

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

int extended_euclidian_algorithm(int a,int b,int &x,int &y){
	if(b==0){
		x=1;
		y=1;
		return a;
	}
	int x1,y1;
	int g=extended_euclidian_algorithm(b,a%b,x1,y1);
	x=y1;
	y=x1-(y1*(a/b));
	return g; 
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	puneetMode();

	int t=0;
	// cin>>t;t--;
	do{
		int a,b,g;cin>>a>>b>>g;
		int x,y;
		cout<<extended_euclidian_algorithm(a,b,x,y)<<endl;
		cout<<x<<","<<y;
	}while(t--);

	return 0;
}