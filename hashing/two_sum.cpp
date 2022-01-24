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

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int>m;
    vector<int>res;
    int n=nums.size();
    for(int i=0;i<n;i++){
        m.insert({nums[i],i});
    }
    for(int i=0;i<n;i++){
        if(m.count(target-nums[i]) >0 && m[(target-nums[i])] != i){
            res.push_back(i);
            res.push_back(m[(target-nums[i])]);
            break;
        }
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
		vector<int>arr(n,0);
		loop(i,0,n)cin>>arr[i];
		int target;cin>>target;
		vector<int>res=twoSum(arr,target);
		cout<<res[0]<<" "<<res[1];
	}while(t--);

	return 0;
}