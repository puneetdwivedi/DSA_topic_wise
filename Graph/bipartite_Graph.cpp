// Link https://leetcode.com/problems/is-graph-bipartite/


class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                queue<int> q;
                q.push(i);
                color[i] = 1;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(auto it : graph[node]){
                        if(color[it] == -1){
                            color[it] = 1 - color[node];
                            q.push(it);
                        }
                        else if(color[it] == color[node])return false;
                        
                    }
                }
            }
        }
        return t
    }
};

