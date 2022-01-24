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


bool valid(string s)
{
    stack<int>st;
    int n=s.length();
    int i=0;
    while(i<n){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }
        else{
            if(st.empty())return false;
            if(st.top() =='{' && s[i]=='}')st.pop();
            else if(st.top() =='[' && s[i]==']')st.pop();
            else if(st.top() =='(' && s[i]==')')st.pop();
            else return false;
        }
        i++;
    }
    if(st.empty()) return true;
    else return false;
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	puneetMode();

	int t=0;
	// cin>>t;t--;
	do{
		
		string st;cin>>st;
		cout<<valid(st);
	}while(t--);

	return 0;
}