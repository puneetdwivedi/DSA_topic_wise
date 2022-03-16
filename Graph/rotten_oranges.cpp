// https://leetcode.com/problems/rotting-oranges/submissions/

class Solution {
public:
    
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int total = 0;
        queue<pair<int,int>> q;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1) total++;
            }
        }
        int time = 0;
        while(!q.empty()){
            int n = q.size();
            if(total == 0) break;
            time++;
            for(int i = 0; i < n && total; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                if(x-1 >=0 && x-1 < grid.size() && grid[x-1][y] == 1){
                    grid[x-1][y] = 2;
                    q.push({x-1,y});
                    total--;
                }
                if(x+1 >=0 && x+1 < grid.size() && grid[x+1][y] == 1){
                    grid[x+1][y] = 2;
                    q.push({x+1,y});
                    total--;
                }
                if(y-1 >= 0 && y-1 < grid[0].size() && grid[x][y-1] == 1){
                    grid[x][y-1] = 2;
                    q.push({x,y-1});
                    total--;
                }
                if(y+1 >= 0 && y+1 < grid[0].size() && grid[x][y+1] == 1){
                    grid[x][y+1] = 2;
                    q.push({x,y+1});
                    total--;
                }
            }
        }
        
        if(total != 0) return -1;
        else return time;
    }
};