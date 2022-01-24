#include<iostream>
#include<math.h>
using namespace std;
#define ll long long int
int no_of_digit(ll n){
	int res=0;
	while(n>0){
		res++;
		n/=10;
	}
	return res;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE

	int t;cin>>t;
	while(t--){
		ll num;cin>>num;
		ll original_num=num;
		ll digit=no_of_digit(num);
		ll armstrong_num=0;
		while(num>0){
			ll last=num%10;
			cout<<pow(last,digit)<<" ";
			armstrong_num=(armstrong_num)+pow(last,digit);
			cout<<armstrong_num<<endl;
			num/=10;
		}
		cout<<armstrong_num<<" ";
		if(armstrong_num==original_num)cout<<"Armstrong";
		else cout<<"Not Armstrong";
		cout<<endl;
		
	}
	return 0;
}