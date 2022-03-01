class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int>res;
        vector<bool>visited(V,false);
        // for(int i=0;i<V;i++){
            if(!visited[0]){
                queue<int>q;
                q.push(0);
                visited[0]=true;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    res.push_back(node);
                    for(auto it: adj[node]){
                        if(!visited[it]){
                            q.push(it);
                            visited[it]=true;
                        }
                    }
                }
            }
        // }
        return res;
    }
};