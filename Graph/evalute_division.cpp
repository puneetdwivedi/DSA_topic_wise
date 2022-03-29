// Problem Link: https://leetcode.com/problems/evaluate-division/submissions/
/* Puneet Dwivedi */


class Solution {
    
    bool dfs(string src, string trgt, map<string,vector<pair<string,double>>> &graph, map<string,bool>& visited, double &ans){
        if(src == trgt){
            return true;
        }
        visited[src] = true;
        for(auto it : graph[src]){
            string nbr = it.first;
            double cost = it.second;
            if(visited[nbr] == false){
                ans *= cost;
                bool res = dfs(nbr, trgt, graph, visited, ans);
                if(res == true) return true;
                ans /= cost;
            }
        }
        
        return false;
    }
public:

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        map<string,vector<pair<string,double>>> graph;
        
        for(int i = 0; i < n; i++){
            string u = equations[i][0];
            string v = equations[i][1];
            graph[u].push_back({v,values[i]});
            graph[v].push_back({u,1.0/values[i]});
        }
        
        vector<double> res;
        for(auto it : queries){
            string src = it[0];
            string trgt = it[1];
            
            if(graph.find(src) != graph.end() && graph.find(trgt) != graph.end()){
                double ans = 1.0;
                map<string,bool> visited;
                bool x = dfs(src, trgt, graph, visited, ans);
                if(x == false) res.push_back(-1.0);
                else res.push_back(ans);
            }
            else res.push_back(-1.0);
        }
            
        return res;
    }
};
