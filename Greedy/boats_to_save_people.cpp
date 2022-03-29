// Problem Link: https://leetcode.com/problems/boats-to-save-people/


class Solution {
public:
    int numRescueBoats(vector<int>& arr, int limit) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int boat = 0;
        
        
        int lo = 0, hi = n-1; 
        while(lo <= hi){
            if(arr[hi] == -1) hi--;
            else if(arr[lo] == -1) lo++;
            else if(lo >= hi){
                boat++;
                arr[lo] = -1;
                lo = lo+1;
                break;
            }
            else if(arr[lo]+ arr[hi] > limit){
                hi--;
            }
            else{
                arr[lo] = -1;
                arr[hi] = -1;
                lo = lo+1;
                hi = hi-1;
                boat ++;
            }
        } 
        
        boat += (n- count(arr.begin(), arr.end(), -1));
    
        return boat;    
    }
};