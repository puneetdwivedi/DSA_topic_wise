
// https://leetcode.com/problems/redundant-connection/

// union find

class Solution {
    int findParent(int u, vector<int> &parent){
        if(u == parent[u]) return u;
        return parent[u] = findParent(parent[u], parent);
    }
    
    void Union(int u, int v, vector<int> &rank, vector<int> &parent){
        u = findParent(u, parent);
        v = findParent(v, parent);
        
        if(rank[u] >= rank[v]){
            parent[v] = u;
            rank[u] += rank[v];
        }
        else {
            parent[u] = v;
            rank[v] += rank[u];
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();   
        
        vector<int> rank(n+1,1);
        vector<int> parent(n+1);
        for(int i = 0; i <= n;i++){
            parent[i] = i;
        }
        
        vector<int> ans;
        for(auto it : edges){
            if(findParent(it[0],parent) != findParent(it[1], parent) ){
                Union(it[0], it[1], rank, parent);
            }
            else{
                ans = it;
            }
        }
        
        return ans;
    }
};