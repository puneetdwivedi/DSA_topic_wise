// Problem Link:  https://leetcode.com/problems/single-element-in-a-sorted-array/
/* Puneet Dwivedi */

#include<bits/stdc++.h>
using namespace std;
#define loop(i,l,h) for(int i=l;i<h;i++)
#define logarr(arr,a,b)	for(int z=(a);z<(b);z++) cout<<(arr[z])<<" ";cout<<endl;
#define endl "\n"
#define mod  1000000007
typedef long long int ll;
typedef long double ld;

void file_input_output(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE
}

/* ***************************************************** */

int singleNonDuplicate(vector<int>& arr) {
    int low=0,high=arr.size()-2;
    while(low<=high){
        int mid=(low+high)>>1;
        if(arr[mid] == arr[mid^1])low=mid+1;
        else high=mid-1;
    }
    return arr[low];
}

int main(){
	clock_t begin=clock();
	file_input_output();


	int t=0;
	//cin>>t;t--;
	do{
		int n;cin>>n;
		vector<int>arr(n);
		loop(i,0,n)cin>>arr[i];
		cout<<singleNonDuplicate(arr);
		
	}while(t--);



	#ifndef ONLINE_JUDGE
		clock_t end=clock();
		cout<<"\n\nFinished in "<<double(end-begin)/CLOCKS_PER_SEC*1000<<" ms";
	#endif 

	return 0;
}