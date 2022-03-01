// Problem link  :: https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& arr) {
        
        int edges = arr.size();
        vector<int> indegree(n, 0);
        vector<vector<int>> graph(n);
        
        for(int i = 0; i < edges; i++){
            int u = arr[i][0];
            int v = arr[i][1];
            indegree[v]++;
            graph[u].push_back(v);
        }
        
        vector<int> res;
        queue<int> q;
        
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            res.push_back(node);
            
            for(auto it : graph[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        reverse(res.begin(), res.end());
        if(res.size() == n) return res;
        
        res.clear();
        return res;
    }
};