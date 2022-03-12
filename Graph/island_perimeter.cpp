class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &grid, int &res){
        if(i <0 || j < 0){
            res++; return ;
        }
        if(i >= grid.size() || j >= grid[0].size()){
            res++; return ;
        }
        if(grid[i][j] == 0){
            res++; return ;            
        } 
        if(grid[i][j] == -1) return ;
        grid[i][j] = -1;
        
        dfs(i+1, j, grid, res);
        dfs(i-1, j, grid, res);
        dfs(i, j+1, grid, res);
        dfs(i, j-1, grid, res);
        
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    dfs(i, j, grid, res);
                    return res;
                }
            }
        }
        return res;
    }
};