class Solution {
public:
    void helper(vector<int> &emp,int i,vector<int> &time,int headid,int &res){
        if(emp[i]==-1){
            res+=time[headid];
            return ;
        }
        res+=time[i];
        helper(emp,emp[i],time,headid,res);
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        int res=0;
        for(int i=0;i<n;i++){
            int t=0;
            helper(manager,i,informTime,headID,t);
            res=max(res,t);
        }
        return res;
    }
};