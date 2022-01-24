#include<bits/stdc++.h>
using namespace std;
#define loop(i,l,h) for(int i=l;i<h;i++)
#define endl "\n"
typedef long long int ll;
typedef long double ld;


inline void puneetMode() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}
/* ***************************************************** */

void sort(stack<int> &s){
   if(s.size()==1){
       return;
   }
   int top=s.top();
   s.pop();
   sort(s);
   vector<int>v;
   while(!s.empty() && s.top()>top){
       v.push_back(s.top());
       s.pop();
   }
   s.push(top);
   while(!v.empty()){
       s.push(v.back());
       v.pop_back();
   }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    puneetMode();

    int t=0;
    cin>>t;t--;
    do{
        int n;cin>>n;
        stack<int>st;
        loop(i,0,n){
            int x;cin>>x;
            st.push(x);
        }
        sort()
    }while(t--);

    return 0;
}