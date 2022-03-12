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
vector<int> djkistra(int n, vector<vector<pair<int,int>>> graph, int src){
	vector<int> dist(n, INT_MAX);
	priority_queue<pair<int,int>> pq;
	dist[src] = 0;
	pq.push({0, src});

	while(!pq.empty()){
		auto tp = pq.top();
		pq.pop();

		int node = tp.second;
		int prv = tp.first;

		for(auto it : graph[node]){
			if(prv + it.second < dist[it.first]){
				dist[it.first] = prv+it.second;
				pq.push({dist[it.first], it.first}); 
			}
		}
	}
	return dist;
}

int main(){
    clock_t begin=clock();
    file_input_output();


    int t=0;
    //cin>>t;t--;
    do{
       
    	int n, e;
    	cin >> n >> e;

    	vector<vector<pair<int, int>>> graph(n);
    	loop(i, 0, e){
    		int u, v, w;
    		cin >> u >> v >> w; 
    		graph[u].push_back({v,w});
    		graph[v].push_back({u,w});
    	}

    	int src;
    	cin >> src;

    	vector<int> dist = djkistra(n, graph, src);

    	cout << "shortest distance from" << src << " to" << endl;

    	for(int i = 0; i<n;i++){
    		cout << i << " " << dist[i] << endl;
    	}




       
    }while(t--);



    #ifndef ONLINE_JUDGE
        clock_t end=clock();
        cout<<"\n\nFinished in "<<double(end-begin)/CLOCKS_PER_SEC*1000<<" ms";
    #endif 

    return 0;
}