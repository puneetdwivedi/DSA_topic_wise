// Problem Link:  https://leetcode.com/problems/find-peak-element/
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
int findPeakElement(vector<int>& arr) {
        int n=arr.size();
        if(n==1)return 0;
        if(arr[0]>arr[1])return 0;
        else if(arr[n-1] >arr[n-2])return n-1;
        int low=1,high=n-2;
        while(low<=high){
            long long mid=low+((high-low)/2);
            if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])return mid;
            else if(arr[mid]>arr[mid-1])low=mid+1;
            else high=mid-1;
        }
        return -1;
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
		cout<<findPeakElement(arr);
		
	}while(t--);



	#ifndef ONLINE_JUDGE
		clock_t end=clock();
		cout<<"\n\nFinished in "<<double(end-begin)/CLOCKS_PER_SEC*1000<<" ms";
	#endif 

	return 0;
}