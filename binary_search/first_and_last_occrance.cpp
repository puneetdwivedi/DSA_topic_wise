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

int first_occurance(vector<int> &arr,int target){
        int low=0,high=arr.size()-1;
        int res=-1;
        while(low<=high){
            int mid=(low+high)>>1;
            if(arr[mid]==target){
                res=mid;
                high=mid-1;
            }
            else if(arr[mid] > target)
                high=mid-1;
            else low=mid+1;
        }
        return res;
        
    }
    int last_occurance(vector<int> &arr,int target){
        int low=0,high=arr.size()-1;
        int res=-1;
        while(low<=high){
            int mid=(low+high)>>1;
            if(arr[mid]==target){
                res=mid;
                low=mid+1;
            }
            else if(arr[mid] > target)
                high=mid-1;
            else low=mid+1;
        }
        return res;
    }
    vector<int> searchRange(vector<int>& arr, int target) {
        vector<int>res(2);
        res[0]=first_occurance(arr,target);
        res[1]=last_occurance(arr,target);
        return res;
    }

int main(){
	clock_t begin=clock();
	file_input_output();


	int t=0;
	//cin>>t;t--;
	do{
		int n,x;cin>>n>>x;
		vector<int>arr(n);
		loop(i,0,n)cin>>arr[i];
		vector<int>res=searchRange(arr,x);
		cout<<res[0]<<" "<<res[1];
		
	}while(t--);



	#ifndef ONLINE_JUDGE
		clock_t end=clock();
		cout<<"\n\nFinished in "<<double(end-begin)/CLOCKS_PER_SEC*1000<<" ms";
	#endif 

	return 0;
}