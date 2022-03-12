// Problem Link: 
/* Puneet Dwivedi */

#include<bits/stdc++.h>
using namespace std;
#define loop(i,l,h) for(int i=(l);i<(h);i++)
#define logarr(arr,a,b) for(int z=(a);z<(b);z++) cout<<(arr[z])<<" ";cout<<endl;
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


int main(){
    clock_t begin=clock();
    file_input_output();


    int t=0;
    //cin>>t;t--;
    do{
       
       	int n, e;
       	cin >> n >> e;
      	vector<vector<pair<int,int>>> graph(n);

      	loop(i, 0, e){
      		int u, v, w;
      		cin >> u >> v >> w;
      		graph[u].push_back({v,w});
      		graph[v].push_back({u,w});
      	}


      	int key[n];
      	bool mst[n];
      	int parent[n];

      	for(int i = 0; i < n; i++){
      		parent[i] = -1;
      		mst[i] = false;
      		key[i] = INT_MAX;
      	}

      	parent[0] = -1;
      	key[0] = 0;

      	// build n edges mst
      	for(int i = 0; i < n-1; i++){
      		int mn = INT_MAX, mn_idx = -1;
      		for(int i = 0; i < n; i++){
      			if(mst[i] == false && mn > key[i]){
      				mn = key[i];
      				mn_idx = i;
      			}
      		}
      		mst[mn_idx] = true;

      		for(auto it : graph[mn_idx]){
      			int wt = it.second;
      			int node = it.first;

      			if(mst[node] == false && key[node] > wt){
      				parent[node] = mn_idx;
      				key[node] = wt; 
      			}
      		}

      	}


      	for(int i = 0; i < n; i++){
      		cout << i << " " << parent[i] << endl; 
      	}


       
    }while(t--);



    #ifndef ONLINE_JUDGE
        clock_t end=clock();
        cout<<"\n\nFinished in "<<double(end-begin)/CLOCKS_PER_SEC*1000<<" ms";
    #endif 

    return 0;
}