// Problem Link: https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/

// dfs O(n^2)

class Solution {
private:
    void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited){
        visited[node] = true;
        for(auto it : graph[node]){
            if(visited[it] == false){
                dfs(it, graph, visited);
            }
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(n);
        
        vector<vector<int>> graph(n);
        for(auto ed : edges){
            graph[ed[0]].push_back(ed[1]);
        }
        
        for(int i = 0; i < n; i++){
            vector<bool> visited(n,false);
            dfs(i, graph, visited);
            for(int k = 0; k < n; k++){
                if(visited[k] == true && k != i) res[k].push_back(i);
            }
        }
        
        return res;
    }
};



// kahn's algorithm

class Solution {
private:
    void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited){
        visited[node] = true;
        for(auto it : graph[node]){
            if(visited[it] == false){
                dfs(it, graph, visited);
            }
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(n);
        
        vector<vector<int>> graph(n);
        vector<int> indegree(n);
        for(auto ed : edges){
            graph[ed[0]].push_back(ed[1]);
            indegree[ed[1]]++;
        }
        
        vector<set<int>> ans(n);
        queue<int> q;
        
        for(int i=0; i < n; i++){
            if(indegree[i] == 0) q.push(i);
            // cout << el << " ";
        }
        // cout << q.size() << endl;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            // cout << node << " ";
            for(auto it : graph[node]){
                ans[it].insert(node);
                
                for(auto it2 : ans[node]){
                    ans[it].insert(it2);
                }
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
            
        for(int i = 0; i < n; i++){
            for(auto it : ans[i]){
                res[i].push_back(it);
            }
        }
            
        return res;
    }
};





