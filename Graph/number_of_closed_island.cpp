// link https://leetcode.com/problems/number-of-closed-islands/submissions/

class Solution {
    
    bool dfs(int i, int j, vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        if(i < 0 || i == n || j < 0 || j == m){
            return false;
        } 
        if(grid[i][j] == 1) return true;
        grid[i][j] = 1;
        int cnt = 0;
        cnt += (!dfs(i-1, j, grid));
        cnt += (!dfs(i+1, j, grid));
        cnt += (!dfs(i, j-1, grid));
        cnt += (!dfs(i, j+1, grid));
        
        if(cnt > 0) return false;
        return true;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        
        int island = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0){
                    island += (dfs(i, j, grid));
                }
            }
        }   
        
        return island;
    }
};