// Problem Link:  https://leetcode.com/problems/number-of-operations-to-make-network-connected/



class Solution {
    
    int findParent(int u, vector<int> &parent){
        if(u == parent[u]) return u;
        return parent[u] = findParent(parent[u], parent);
    }
    
    void Union(int u, int v, vector<int> &parent, vector<int> &rank){
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        // dsu
        vector<int> rank(n,1);
        vector<int> parent(n);
        for(int i = 0; i< n; i++){
            parent[i] = i;
        }
        int cnt = 0;
        for(auto it : connections){
            if(findParent(it[0], parent) != findParent(it[1], parent)){
                Union(it[0], it[1], parent, rank);
            }
            else{
                cnt++;
            }
        }    
        set<int> s;
        for(int i=0; i< n; i++){
            s.insert(findParent(i,parent));
            // cout << parent[i] << " ";
        }
        
        // cout << cnt << endl;
        // cout << s.size();
        
        if(cnt >= s.size()-1) return s.size()-1;
        return -1;
        
        
    }
};