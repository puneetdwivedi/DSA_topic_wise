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

int extended_euclidian(int a,int b,int &x,int &y){
	if(b==0){
		x=1;y=0;
		return a;
	}
	int x1,y1;
	int g=extended_euclidian(b,a%b,x1,y1);
	x=y1;
	y=x1-(y1*(a/b));
	return g;
}


bool find_solution(int a,int b,int c,int &x,int &y){
	int x1, y1;
	// if a and b are negitve then make it postive
 	if(a<0)a*=-1;
	if(b<0)b*=-1; 
	int g=extended_euclidian(a,b,x1,y1);
	if(c%g !=0)return false;
	x=x1*(c/g);
	y=y1*(c/g);
	// according to a and b make the x and y positive and negative
	if(a<0)x*=-1;
	if(b<0)y*=-1;
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
		int a,b,c;cin>>a>>b>>c;
		int x,y;
		// cout<<find_solution(a,b,c,x,y)<<endl;
		if(find_solution(a,b,c,x,y))cout<<x<<" "<<y;
		else cout<<"Not exist";

	}while(t--);

	return 0;
}