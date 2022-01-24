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

// brute force o(n*p)
int chiense_remainder_bf(int nums[],int rem[],int n){
	int p=1;
	loop(i,0,n){
		p*=nums[i];
	}
	for(int i=1;i<p;i++){
		int x=0;
		for(int j=0;j<n;j++){
			if(i%nums[j]==rem[j])x++;
			else break;
		}
		if(x==n)return i;
	}
	return p-1;
}

// optimized version of brute force 
int chiense_remainder_bfo(int nums[],int rem[],int n){
	int diff=1;
	int strt=nums[0];
	for(int i=0;i<n;i++){
		if(rem[i]>strt){
			strt=rem[i];
			diff=nums[i];
		}
	}
	int p=1;
	loop(i,0,n){
		p*=nums[i];
	}
	for(int i=strt;i<p;i+=diff){
		int x=0;
		for(int j=0;j<n;j++){
			if(i%nums[j]==rem[j])x++;
			else break;
		}
		if(x==n)return i;
	}
	return p-1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	puneetMode();

	int t=0;
	// cin>>t;t--;
	do{
		int n;cin>>n;
		int nums[n],rem[n];
		loop(i,0,n)cin>>nums[i];
		loop(i,0,n)cin>>rem[i];
		cout<<chiense_remainder_bfo(nums,rem,n);
	}while(t--);

	return 0;
}