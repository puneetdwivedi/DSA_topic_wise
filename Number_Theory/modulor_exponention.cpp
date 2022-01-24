#include<iostream>
using namespace std;

// a topower b under modulo m
int modulor_exponention_iterative(int a,int b,int m){
	int res=1;
	while(b){
		// even
		if((b&1) ==0){
			b/=2;
			a=((a%m)*(a%m))%m;
		}
		// odd
		else{
			res=((res%m)*(a%m))%m;
			b--;
		}
	}
	return res;
}

int modulor_exponention_recursive(int a,int b,int m){
	if(b==0)return 1;
	if((b&1)==0)return modulor_exponention_recursive(((a%m)*(a%m))%m,b/2,m);
	else return ((a%m)*(modulor_exponention_recursive(a,b-1,m)%m))%m;
}


int main(){

	#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int a,b;cin>>a>>b;
    int m=(1e9)+7;
    cout<<modulor_exponention_iterative(a,b,m);
    cout<<endl;
    cout<<modulor_exponention_recursive(a,b,m);

	return 0;
}