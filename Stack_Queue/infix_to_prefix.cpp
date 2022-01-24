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

int precedence(char ch){
	if(ch=='+')return 1;
	else if(ch=='-')return 1;
	else if(ch=='*')return 2;
	else if(ch=='/')return 2;
	else return 3;
}

string infixtoPrefix(string s){
	int n=s.length();
	stack<int>st;
	string res="";
	int i=n-1;
	while(i>=0){
		if(s[i]>='a' && s[i]<='z'){
			res.push_back(s[i--]);
		}
		else if(s[i] ==')'){
			st.push(s[i--]);
		}
		else if(s[i]=='('){
			while(st.top() != ')'){
				res.push_back(st.top());
				st.pop();
			}
			st.pop();
			i--;
		}
		else{
			if(st.empty() || st.top()==')'){
				st.push(s[i--]);
			}
			else if(precedence(s[i]) > precedence(st.top())){
				st.push(s[i--]);
			}
			else{
				res.push_back(st.top());
				st.pop();
			}
		}
	}
	while(!st.empty()){
		res.push_back(st.top());
		st.pop();
	}
	reverse(res.begin(),res.end());
	return res;
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
		cout<<infixtoPrefix(st);
	}while(t--);

	return 0;
}