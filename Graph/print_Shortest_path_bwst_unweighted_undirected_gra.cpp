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

bool shortest_path(int n, vector<vector<int>> graph, int src, int trgt, vector<int> &pred){
	vector<int> dist(n, INT_MAX);
	queue<int> q;

	q.push(src);
	dist[src] = 0;
	pred[src] = -1;

	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(auto it : graph[node]){
			if(dist[it] > dist[node]+1){
				dist[it] = dist[node] + 1;
				pred[it] = node;
				q.push(it);
			}
			if(it == trgt) return true;
		}
	}
	return false;
}

int main(){
    clock_t begin=clock();
    file_input_output();


    int t=0;
    //cin>>t;t--;
    do{
       int n, e;
       cin >> n >> e;
       vector<vector<int>> graph(e);
       loop(i, 0, e){
       		int u, v;
       		cin >> u >> v;
       		graph[u].push_back(v);
       		graph[v].push_back(u);
       }

       int src, trgt;
       cin >> src >> trgt;

       vector<int> pred(n, -1);

       bool res = shortest_path(n, graph, src, trgt, pred);

       if(res == false) cout << "No path exist" << endl;

       else{
       		cout << " shortest_path between " << src << " and " << trgt << endl;
       		vector<int> path;
       		path.push_back(trgt);
       		int crwl = trgt;
       		while(pred[crwl] != -1){
       			path.push_back(pred[crwl]);
       			crwl = pred[crwl];
       		}

       		for(int i = path.size()-1; i >= 0; i--){
       			cout << path[i] << " ";
       		}
       }





       
    }while(t--);



    #ifndef ONLINE_JUDGE
        clock_t end=clock();
        cout<<"\n\nFinished in "<<double(end-begin)/CLOCKS_PER_SEC*1000<<" ms";
    #endif 

    return 0;
}