// Problem Link: https://leetcode.com/problems/search-a-2d-matrix/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int m=arr[0].size();
        int n=arr.size();
        int i = 0;
        int j = m-1;
        while(i>=0 && i < n && j < m && j >= 0){
            if(target == arr[i][j]) return true;
            else if(target > arr[i][j]) i++;
            else j--;
        }
        
        return false;
    }
};