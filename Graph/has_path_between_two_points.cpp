class Solution {
public:
    bool exist(int start, int end, vector<vector<int>> &edges, vector<bool> &visited){
        if(start == end)return true;
        visited[start] = true;
        cout << start << " ";
        for(auto it : edges[start]){
            if(!visited[it]){
                bool result=exist(it,end,edges,visited);
                if(result)return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>graph(n); 
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];           
            int v = edges[i][1];
            graph[u].push_back(v);      
            graph[v].push_back(u);
        }
        vector<bool> visited(n,false);
        return exist(source,destination,graph,visited);
    }
};