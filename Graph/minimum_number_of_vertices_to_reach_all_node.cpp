// Problem Link  : https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> graph(n);   
        int e = edges.size();
        vector<int> indegree(n, 0);
        
        for(int i = 0; i < e; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            indegree[v]++;
        }
        
        vector<int> res;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) res.push_back(i);
        }
        
        return res;
    }
};