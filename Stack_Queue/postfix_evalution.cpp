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


int calc(int x,int y,char ch){
    if(ch=='+')return x+y;
    else if(ch=='-')return x-y;
    else if(ch=='*')return x*y;
    else return x/y;
}
int evaluatePostfix(string s)
{
    int n=s.length();
    stack<int>st;
    int i=0;
    while(i<n){
        if(s[i]>='0' && s[i]<='9'){
            st.push((s[i]-'0'));
              
        }
        else{
            int x=st.top();st.pop();
            int y=st.top();st.pop();
            y=calc(y,x,s[i]);
            st.push(y);
        }
        i++;
    }
    return st.top();
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
		cout<<evaluatePostfix(st)<<endl;
	}while(t--);

	return 0;
}