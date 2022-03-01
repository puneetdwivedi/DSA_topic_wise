// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
private:
    bool cycle(int i, vector<int> graph[], vector<int> &visited){
        queue<pair<int,int>>q;
        q.push({i ,-1});
        visited[i] = true;
        while(!q.empty()){
            auto tp = q.front();
            q.pop();
            int node = tp.first;
            int prv = tp.second;
            for(auto it : graph[node]){
                if(!visited[it]){
                    visited[it] = true;
                    q.push({it,node});
                }
                else if(it != prv)return true;
            }
        }
        return false;
    }    
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        vector<int> visited(v+1,false);
        for(int i = 0; i < v; i++){
            if(!visited[i]){
                bool res = cycle(i, adj, visited);
                if(res == true) return true;
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends