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

void insertatbottom(stack<int> &st,int top){
        if(st.size()==0){
            st.push(top);return;
        }
        int x=st.top();
        st.pop();
        insertatbottom(st,top);
        st.push(x);
    }
    void reversestack(stack<int> &st){
        if(st.size()==1 || st.size()==0)return ;
        int top=st.top();
        st.pop();
        reversestack(st);
        insertatbottom(st,top);
    }
    void clonestack(stack<int> st, stack<int>& cloned)
    {
        reversestack(st);
        while(!st.empty()){
            int x=st.top();
            st.pop();
            cloned.push(x);
        }
       return;
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
		for(int i=0;i<n;i++){
			int x;cin>>x;
			st.push(x);
		}
		stack<int>cl;
		clonestack(st,cl);

	}while(t--);

	return 0;
}