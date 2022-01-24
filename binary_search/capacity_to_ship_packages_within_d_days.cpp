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
bool isshipped(vector<int>& arr, int days,int mid){
        int n=arr.size();
        int req=1;
        int shipped=0;
        for(int i=0;i<n;i++){
            if(arr[i]>mid)return false;
            if(shipped+arr[i] > mid){
                req++;
                shipped=arr[i];
            }
            else{
                shipped+=arr[i];
            }
        }
        if(req>days)return false;
        return true;
    }



int shipWithinDays(vector<int>& arr, int days) {
        int n=arr.size();
        int low=*min_element(arr.begin(),arr.end());
        int high=10000000;
        int res=-1;
        while(low<=high){
            int mid=(low+high)>>1;
            if(isshipped(arr,days,mid)){
                res=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return res;
    }

int main(){
	clock_t begin=clock();
	file_input_output();


	int t=0;
	//cin>>t;t--;
	do{
		int n,d;cin>>n>>d;
		vector<int>arr(n);
		loop(i,0,n)cin>>arr[i];
		cout<<shipWithinDays(arr,d);

		
	}while(t--);



	#ifndef ONLINE_JUDGE
		clock_t end=clock();
		cout<<"\n\nFinished in "<<double(end-begin)/CLOCKS_PER_SEC*1000<<" ms";
	#endif 

	return 0;
}