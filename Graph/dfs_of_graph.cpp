class Solution {
  public:
    void dfs(int node,vector<bool> &visited, vector<int> adj[], vector<int> &res){
        res.push_back(node);
        visited[node]=true;
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(it,visited,adj,res);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        vector<int> res;
        vector<bool>visited(v+1,false);
        dfs(0,visited,adj,res);
        return res;
    }
};