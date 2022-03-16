class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int m = popped.size();
        int n = pushed.size();
        int i = 0, j = 0;
        bool res = true;
        while(j < m){
            if((st.empty() || st.top() != popped[j]) && i < n){
                st.push(pushed[i++]);
            }
            if(st.top() == popped[j]){
                st.pop();
                j++;
                continue;
            }
            if(i == n && j < m){
                res = false;
                break;
            }
        }
        
        return res;
    }
};