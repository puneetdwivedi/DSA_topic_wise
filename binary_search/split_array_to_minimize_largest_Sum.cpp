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



bool cansplit(vector<int>& arr, int m,int mid){
        int array=1;
        long long sum=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>mid)return false;
            if(sum+arr[i] > mid){
                sum=arr[i];
                array++;
            }
            else{
                sum+=(arr[i]);
            }
        }
        if(array > m)return false;
        return true;
    }  

int splitArray(vector<int>& arr, int m) {
        int low=*(min_element(arr.begin(),arr.end()));
        int high=0;
        for(int i=0;i<arr.size();i++){
            high+=arr[i];
        }
        int res=*(max_element(arr.begin(),arr.end()));
        while(low<=high){
            int mid=(low+((high-low)/2));
            if(cansplit(arr,m,mid)){
                res=mid;
                high=mid-1;
            } 
            else{
                low=mid+1;
            }
        }
        return res;
    }
int main(){
	clock_t begin=clock();
	file_input_output();


	int t=0;
	//cin>>t;t--;
	do{
		int n,m;cin>>n>>m;
		vector<int>arr(n);	
		loop(i,0,n)cin>>arr[i];
		cout<<splitArray(arr,m);
		
	}while(t--);



	#ifndef ONLINE_JUDGE
		clock_t end=clock();
		cout<<"\n\nFinished in "<<double(end-begin)/CLOCKS_PER_SEC*1000<<" ms";
	#endif 

	return 0;
}