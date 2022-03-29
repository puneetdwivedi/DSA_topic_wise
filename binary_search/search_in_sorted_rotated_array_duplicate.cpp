// link https://leetcode.com/problems/search-in-rotated-sorted-array-ii/submissions/

class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int lo = 0, hi = arr.size() - 1;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            
            if(arr[mid] == target){
                return true;
            }
            else if(arr[lo] == arr[mid] && arr[mid] == arr[hi]){
                lo++; hi--;
            }
            
            else if(arr[lo] <= arr[mid]){
                if(arr[lo] <= target && target <= arr[mid]){
                    hi = mid -1;
                }
                else lo = mid + 1;
            }
            else{
                if(arr[mid] <= target && target <= arr[hi]){
                    lo = mid+1;
                }
                else hi = mid-1;
            }
        }
        
        return false;
    }
};