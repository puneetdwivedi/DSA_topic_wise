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

int maximumsumofsizearrayofsizek(int arr[],int n,int k){
	int w_sum=0;
	for(int i=0;i<k;i++)w_sum+=arr[i];
	int res=w_sum;
	for(int i=1;i<=n-k;i++){
		w_sum+=arr[i+k-1];
		w_sum-=arr[i-1];
		res=max(res,w_sum);
	}
	return res;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	puneetMode();

	int t=0;
	// cin>>t;t--;
	do{
		int n,k;cin>>n>>k;
		int arr[n];
		loop(i,0,n)cin>>arr[i];
		cout<<maximumsumofsizearrayofsizek(arr,n,k);
		cout<<endl;
	}while(t--);

	return 0;
}