// Porblem Link : https://leetcode.com/problems/course-schedule/


class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& arr) {
        int edges = arr.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n,0);
        
        // making graph and caluculating indegree for every node
        for(int i = 0; i < edges; i++){
            int u = arr[i][0];
            int v = arr[i][1];
            graph[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        int count = 0;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            count++;
            
            for(auto it : graph[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        // cout << count << endl;
        // for(auto in : indegree) cout << in <<" ";
        
        if(count >= n) return true;
        return false;
    }
};