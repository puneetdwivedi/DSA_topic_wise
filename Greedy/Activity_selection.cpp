// Problem Link: https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1/#

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    static bool comp(pair<int,int>& el1, pair<int,int>& el2){
        if(el1.second < el2.second) return true;
        else if(el1.second == el2.second){
            if(el1.first < el2.first) return true;
        }
        
        return false;
    }   
    
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int,int>> arr(n);
        for(int i= 0; i < n; i++){
            arr[i].first = start[i];
            arr[i].second = end[i];
        }
        
        sort(arr.begin(), arr.end(), comp);
        
        int res = 1;
        int et = arr[0].second;
        for(int i = 1; i < n; i++){
            if(arr[i].first > et){
                res++;
                et = arr[i].second;
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends