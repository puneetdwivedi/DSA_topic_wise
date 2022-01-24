#include<iostream>
using namespace std;

const int md=1e9+7;
const int n=1e6;
int fact[n+1];

int power(int x,int n){
	int res=1;
	while(n){
		if(n%2==0){
			x=(x*1LL*x)%md;
			n/=2;
		}
		else{
			n--;
			res=(res*1LL*x)%md;
		}
	}
	return res;
}


void generate_Factorial(){
	fact[0]=fact[1]=1;
	for(int i=2;i<=n;i++){
		fact[i]=((i%md)*(fact[i-1]%md))%md;
	}
}

int binomial_cofficient(int n,int r){
	if(r>n)return 0;
	int res=fact[n];
	res=(res*1LL*power(fact[r],md-2))%md;
	res=(res*1LL*power(fact[n-r],md-2))%md;
	return res;
}


int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    generate_Factorial();
    int n,r;cin>>n>>r;
    cout<<binomial_cofficient(n,r);
 
	return 0;
}