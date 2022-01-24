// Problem Link: https://leetcode.com/problems/sqrtx/
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

 int mySqrt(int x) {
    if(x==0)return 0;
    int low=1,high=x;
    while(low<=high){
        long long mid=low+((high-low)/2);
        if(mid==x/mid)return mid;
        else if(mid*mid >x)high=mid-1;
        else low=mid+1;
    }
    return high;
}

int main(){
	clock_t begin=clock();
	file_input_output();


	int t=0;
	//cin>>t;t--;
	do{
		
		
	}while(t--);



	#ifndef ONLINE_JUDGE
		clock_t end=clock();
		cout<<"\n\nFinished in "<<double(end-begin)/CLOCKS_PER_SEC*1000<<" ms";
	#endif 

	return 0;
}