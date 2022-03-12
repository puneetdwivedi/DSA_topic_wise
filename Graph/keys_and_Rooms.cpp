// https://leetcode.com/problems/keys-and-rooms/



class Solution {
public:
    void dfs(int node, vector<vector<int>> graph, vector<int> &visited){
        visited[node] = true;
        
        for(auto it : graph[node]){
            if(!visited[it]){
                dfs(it, graph, visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, false);
        dfs(0, graph, visited);
        
        if(count(visited.begin(),visited.end(),false) == 0) return true;
        return false;
        
    }
};
