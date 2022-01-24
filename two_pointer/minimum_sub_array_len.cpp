// Problem Link: 
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
int minSubArrayLen(int target, vector<int>& arr) {
        int n=arr.size();
        int curr=arr[0];
        int i=0;
        int j=1;
        int res=n+1;
        while(j<n){
            if(curr>=target){
                res=min(res,j-i);
                cout<<j<<" "<<i<<endl;
                curr-=arr[i];i++;
            }
            else{
                curr+=arr[j];
                j++;
            }
        }
        while(curr>=target && i<n){
            if(curr>=target){
                cout<<j<<" "<<i<<endl;
                res=min(res,j-i);
            }
            curr-=arr[i];i++;
         }
        if(res==n+1)return 0;
        return res;
    }

int main(){
	clock_t begin=clock();
	file_input_output();


	int t=0;
	//cin>>t;t--;
	do{
		int n;cin>>n;
		int target;cin>>target;
		vector<int>arr(n);
		loop(i,0,n)cin>>arr[i];
		cout<<minSubArrayLen(target,arr)<<endl;
		
	}while(t--);



	#ifndef ONLINE_JUDGE
		clock_t end=clock();
		cout<<"\n\nFinished in "<<double(end-begin)/CLOCKS_PER_SEC*1000<<" ms";
	#endif 

	return 0;
}