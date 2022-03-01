class Solution {
public:
    
    vector<vector<int>> result;
    void allPath(vector<vector<int>>& graph,int start,int end,vector<int>&path,vector<bool>&visited){
        if(start==end){
            path.push_back(start);
            result.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(start);
        visited[start]=true;
        for(auto &neighbour :graph[start]){
            if(!visited[neighbour]){
                allPath(graph,neighbour,end,path,visited);
            }
        }
        path.pop_back();
        visited[start]=false;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool>visited(n,false);
        vector<int>path;
        allPath(graph,0,n-1,path,visited);
        return result;
    }
};