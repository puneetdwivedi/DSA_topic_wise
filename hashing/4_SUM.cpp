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

vector<vector<int>> four_sum(int arr[],int n,int target){
	sort(arr,arr+n);
	vector<vector<int>>res;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int target2=target-(arr[i]+arr[j]);
			int front=j+1;
			int back=n-1;
			while(front<back){
				int twosum=arr[front]+arr[back];
				if(twosum < target2)front++;
				else if(twosum > target2)back--;
				else{
					vector<int>v(4,0);
					v[0]=arr[i];v[1]=arr[j];
					v[2]=arr[front];v[3]=arr[back];
					res.push_back(v);
					while(front<back && arr[front]==v[2])front++;
					while(front < back && arr[back]==v[3])back--;
				}
			}
			while(j+1<n && arr[j] == arr[j+1])j++;
		}
		while(i+1<n && arr[i] == arr[i+1])i++;
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
		int n,target;cin>>n>>target;
		int arr[n];
		loop(i,0,n)cin>>arr[i];
		vector<vector<int>>res=four_sum(arr,n,target);
		for(int i=0;i<res.size();i++){
			for(int j=0;j<4;j++)cout<<res[i][j]<<" ";
			cout<<endl;
		}
	}while(t--);

	return 0;
}

/*
TC n^3

*/