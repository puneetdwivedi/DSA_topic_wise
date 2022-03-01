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
vector<int> shortest_path(int n, vector<vector<int>> graph, int source){
	queue<int> q;
	vector<int> dist(n, INT_MAX);

	dist[source] = 0;
	q.push(source);

	while(!q.empty()){
		int node = q.front();
		q.pop();

		for(auto it : graph[node]){
			if(dist[node]+1 < dist[it]){
				dist[it] = dist[node] + 1;
				q.push(it);
			}
		}
	}
	return dist;
}

int main(){
    clock_t begin=clock();
    file_input_output();


    int t=0;
    // cin>>t;t--;
    do{
       int n;
       cin >> n;
       vector<vector<int>> graph(n);
       int e; 
       cin >> e;
       loop(i, 0, e){
       		int u, v;
       		cin >> u >> v;
       		graph[u].push_back(v);
       		graph[v].push_back(u);
       }

       int src; cin >> src;

       

       vector<int> dist = shortest_path(n, graph, src);
       cout << "shortest path from 2 to " << endl;
       for(int i = 0; i < dist.size(); i++){
       		cout << i << " : " << dist[i] <<endl; 
       }


       
    }while(t--);



    #ifndef ONLINE_JUDGE
        clock_t end=clock();
        cout<<"\n\nFinished in "<<double(end-begin)/CLOCKS_PER_SEC*1000<<" ms";
    #endif 

    return 0;
}