// Problem Link: 
/* Puneet Dwivedi */

#include<bits/stdc++.h>
using namespace std;
#define loop(i,l,h) for(int i=(l);i<(h);i++)
#define logarr(arr,a,b) for(int z=(a);z<(b);z++) cout<<(arr[z])<<" ";cout<<endl;
#define endl "\n"
#define mod  1000000007
#define mod1 998244353
#define INF 1e18
#define all(x) (x).begin(), (x).end()
typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pi;

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


class Point{
public:
	int u;
	int v;
	int w;
	Point(){};
	Point(int u,int v, int w){
		this -> u = u;
		this -> v = v;
		this -> w = w;
	}
};

bool comp(Point a, Point b) {
    return a.w < b.w; 
}


int findParent(int u, vector<int> &parent){
	if(parent[u] == u) return u;
	return parent[u] = findParent(parent[u], parent);
}

void Union(int u, int v, vector<int> &rank, vector<int> &parent){
	u = findParent(u, parent);
	v = findParent(v, parent);

	if(rank[u] > rank[v]){
		parent[v] = u;
		rank[u] += rank[v];
	}
	else {
		parent[u] = v;
		rank[v] += rank[u];
	}
}



int kruskal_algorithm(int n, vector<Point> edges){
	sort(all(edges), comp);
	
	// dsu
	vector<int> rank(n, 1);
	vector<int> parent(n);
	for(int i = 0; i< n;i++){
		parent[i] = i;
	}


	int cost = 0;
	vector<Point> ans;

	for(auto it : edges){
		if(findParent(it.u, parent) != findParent(it.v, parent)){
			cost += it.w;
			ans.push_back(it);
			Union(it.u, it.v, rank, parent);
		}
	}

	cout << cost << endl;
	for(auto it : ans){
		cout << it.u << " " << it.v << endl;
	}

	return cost;
}



int main(){
    clock_t begin=clock();
    file_input_output();


    int t=0;
    // cin>>t;t--;
    do{
       int n; cin >> n;
       int m; cin >> m;

       vector<Point> edges;
       for(int i = 0; i<  m; i++){
       		int u,v,w;
       		cin >> w >> u >> v;
       		Point p(u,v,w);
       		edges.push_back(p);
       }


       kruskal_algorithm(n, edges);
       
    }while(t--);



    #ifndef ONLINE_JUDGE
        clock_t end=clock();
        cout<<"\n\nFinished in "<<double(end-begin)/CLOCKS_PER_SEC*1000<<" ms";
    #endif 

    return 0;
}