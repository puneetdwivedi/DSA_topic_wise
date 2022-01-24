#include<iostream>
using namespace std;
const int md=1000000000+7;

const int n=1e6;
int fact[n];
void find_factorial(){
	fact[0]=fact[1]=1;
	for(int i=2;i<n;i++){
		fact[i]=((i%md)*(fact[i-1]%md))%md;
	}
}

int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
	find_factorial();
	int q;cin>>q;
	while(q--){
		int x;cin>>x;	
		cout<<fact[x]<<endl;

	}

	return 0;
}