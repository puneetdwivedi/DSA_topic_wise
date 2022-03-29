// link https://leetcode.com/problems/search-in-rotated-sorted-array/


class Solution {
public:
    int search(vector<int>& arr, int target) {
        int lo = 0;
        int hi = arr.size()-1;
        
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            
            if(arr[mid] == target) return mid;
            // left part is sorted
            else if(arr[lo] <= arr[mid]){
                if(arr[lo] <= target && target <= arr[mid]){
                    hi = mid-1;
                }
                else lo = mid+1;
            }
            // right part is sorted
            else{
                if(arr[mid] <= target && target <= arr[hi]){
                    lo = mid+1;
                }
                else hi = mid-1;
            }
        }
        
        return -1;
    }
};