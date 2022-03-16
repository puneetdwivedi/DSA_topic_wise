class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        int cost = 0;
        
        map<pair<int,int>, int> dist_key;
        map<pair<int,int>, bool> mst;
        map<pair<int,int>, pair<int,int>> parent;
        
        for(int i = 0; i < n; i++){
            int u = points[i][0];
            int v = points[i][1];
            pair<int,int> p ={u,v};
            dist_key[p] = INT_MAX;
            mst[p] = false;
        }
        pair<int,int> p = {points[0][0], points[0][1]};
        dist_key[p] = 0;
        
        for(int i = 0; i< n-1; i++){
            pair<int,int> min_point = {-1,-1};
            int dist = INT_MAX;
            for(auto it : dist_key){
                if(mst[it.first] == false && dist_key[it.first] < dist){
                    dist = dist_key[it.first];
                    min_point = it.first;
                }
            }
            
            mst[min_point] = true;
            
            for(auto it : mst){
                int wt = abs(min_point.first - it.first.first) + abs(min_point.second - it.first.second);
                pair<int,int> point = it.first;
                
                if(mst[point]  == false && dist_key[point] > wt){
                    dist_key[point] = wt;
                    parent [point] = min_point;
                }
            }
            
        }
        for(auto it : parent){
            cost += abs(it.first.first - it.second.first) + abs(it.first.second - it.second.second);
        }
        return cost;
        
    }
};