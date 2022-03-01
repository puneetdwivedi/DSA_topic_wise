// Problem Link: https://leetcode.com/problems/majority-element-ii/
/* Puneet Dwivedi */


class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n = arr.size();
        
        map<int,int> mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
        }
        
        vector<int> res;
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it->second > n/3){
                res.push_back(it->first);
            }
        }
        return res;
    }
};


// approch 2 moores voting algorithm


class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        
        int maj_el = arr[0];
        int count = 1;
        for(int i = 0; i < n; i++){
            if(maj_el  == arr[i]){
                count++;
            }
            else{
                count--;
                if(count == 0){
                    count = 1;
                    maj_el = arr[i];
                }
            }
        }
        return maj_el;
    }
};