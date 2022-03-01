// https://leetcode.com/problems/remove-covered-intervals/
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& arr) {
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        int x = arr[0][0];
        int y = arr[0][1];
        int res = 0;
        for(int i = 0; i < n; i++){
            if(arr[i][0] > x && arr[i][1] ) res++;
            
            if(arr[i][1] > y){
                x = arr[i][0];
                y = arr[i][i];
            }
        }
        return res;
    }
};