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

int largest_subarray_zerosum(int arr[],int n){
	unordered_map<int,int>mp;
	int sum=0,res=0;
	mp[0]=-1;
	for(int i=0;i<n;i++){
		sum+=arr[i];
		if(mp.find(sum) != mp.end()){
			res=max(res,i-mp[sum]);
		}
		else mp[arr[i]]=i;
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
		int n;cin>>n;
		int arr[n];
		loop(i,0,n)cin>>arr[i];
		cout<<largest_subarray_zerosum(arr,n);
	}while(t--);

	return 0;
}