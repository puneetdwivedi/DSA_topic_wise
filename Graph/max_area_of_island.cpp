// https://leetcode.com/problems/max-area-of-island/submissions/

class Solution {
    int bfs(int i, int j, vector<vector<int>>& graph){
        int area = 0;
        int n = graph.size();
        int m = graph[0].size();
        queue<pair<int,int>> q;
        q.push({i, j});
        area++;
        graph[i][j]=0;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            if(x+1 < n && graph[x+1][y] == 1){
                graph[x+1][y] =0;
                q.push({x+1, y});
                area++;
            }
            if(x-1 >=0  && graph[x-1][y] == 1){
                graph[x-1][y] =0;
                q.push({x-1, y});
                area++;
            }
            if(y+1 < m && graph[x][y+1] == 1){
                graph[x][y+1] = 0;
                q.push({x, y+1});
                area++;
            }
            if(y-1 >=0 && graph[x][y-1]==1){
                graph[x][y-1] = 0;
                q.push({x, y-1});
                area++;
            }
        }
        
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();
        int area = 0;
        for(int i = 0; i< n; i++){
            for(int j = 0; j < m; j++){
                if(graph[i][j] == 1){
                    area = max(area, bfs(i, j, graph));
                }
            }
        }
        return area;
    }
};