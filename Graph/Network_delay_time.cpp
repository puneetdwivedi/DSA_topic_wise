// https://leetcode.com/problems/network-delay-time/

// djkstria algo

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto el : times){
            graph[el[0]].push_back({el[1], el[2]});
        }
        
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int,int>> pq;
        pq.push({0, k});
        
        while(!pq.empty()){
            auto tp = pq.top();
            pq.pop();
            int node = tp.second; 
            int prv_dist = tp.first;
            
            for(auto it : graph[node]){
                int wt = it.second;
                int nbr = it.first;
                
                if(dist[nbr] > prv_dist+wt){
                    dist[nbr] = prv_dist + wt;
                    pq.push({prv_dist+wt, nbr});
                }
            }
            
        }
        int res = 0;
    
        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX) return -1;
            res = max(res, dist[i]);
        }
        return res;
    }
};


