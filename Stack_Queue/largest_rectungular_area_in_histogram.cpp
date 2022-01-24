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

vector<long long> pse(long long arr[],int n){
    vector<long long >res(n);
    stack<long long >st;
    int i=0;
    while(i<n){
    if(st.empty()){
        res[i]=-1;
        st.push(i++);
    }
    else if(arr[st.top()]<arr[i]){
        res[i]=st.top();
        st.push(i++);
    }
    else st.pop();
    }
    return res;
}

vector<long long> nse(long long arr[],int n){
    vector<long long >res(n);
    stack<long long >st;
    int i=n-1;
        while(i>=0){
        if(st.empty()){
            res[i]=n;
            st.push(i--);
        }
        else if(arr[st.top()]< arr[i]){
            res[i]=st.top();
            st.push(i--);
        }
        else st.pop();
    }
    return res;
}
long long getMaxArea(long long arr[], int n)
{
    vector<long long>left=pse(arr,n);
    vector<long long>right=nse(arr,n);
    long long res=0;
    for(int i=0;i<n;i++){
        int x=i-left[i]-1;
        int y=right[i]-i-1;
        long long t=(x+y+1)*arr[i];
        res=max(res,t);
    }
    return res;
        
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
        long long arr[n];
        loop(i,0,n)cin>>arr[i];
        cout<<getMaxArea(arr,n);
    }while(t--);

    return 0;
}