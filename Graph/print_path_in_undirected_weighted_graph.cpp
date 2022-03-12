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

bool djkistra(int n, vector<vector<pair<int,int>>> graph, int src, int trgt, vector<int> &pred){
	vector<int> dist(n, INT_MAX);

	priority_queue<pair<int,int>> pq;
	dist[src] = 0;
	pq.push({0, src});

	bool res = false;
	while(!pq.empty()){
		auto tp = pq.top();
		pq.pop();
		int node = tp.second;
		int prvdist =  tp.first;

		for(auto it : graph[node]){
			if(prvdist + it.second < dist[it.first]){
				dist[it.first] = prvdist + it.second;
				pred[it.first] = node;
				pq.push({dist[it.first], it.first}); 
			}
			if(it.first == trgt) res = true;
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
       
    	int n, e;
    	cin >> n >> e;

    	vector<vector<pair<int, int>>> graph(n);
    	loop(i, 0, e){
    		int u, v, w;
    		cin >> u >> v >> w; 
    		graph[u].push_back({v,w});
    		graph[v].push_back({u,w});
    	}

    	int src, trgt;
    	cin >> src >> trgt;

    	vector<int> pred(n, -1);

    	bool res = djkistra(n, graph, src, trgt, pred);
    	if(res == false) cout << "No path exist" << endl;
    	else { 
    		cout << "Path from " << src  << " to " << trgt << endl;
    		int crwl = trgt;
    		vector<int> path;
    		path.push_back(trgt);
    		while(pred[crwl] != -1){
    			path.push_back(pred[crwl]);
    			crwl = pred[crwl];
    		}

    		for(int i = path.size()-1; i >= 0; i--){
    			cout << path[i] << " ";
    		}
    		cout << endl;

    	}


       
    }while(t--);



    #ifndef ONLINE_JUDGE
        clock_t end=clock();
        cout<<"\n\nFinished in "<<double(end-begin)/CLOCKS_PER_SEC*1000<<" ms";
    #endif 

    return 0;
}