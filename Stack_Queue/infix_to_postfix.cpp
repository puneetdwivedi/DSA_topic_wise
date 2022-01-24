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
        if(ch=='+'||ch=='-')return 1;
        else if(ch=='*' || ch=='/')return 2;
        else return 3;
    }
string infixToPostfix(string s)
{
    stack<char>st;
    string res="";
    int i=0;
    int n=s.length();
    while(i<n){
        if(s[i]>='a' && s[i]<='z'){
            res.push_back(s[i++]);
        }
        else if(s[i]=='('){
            st.push(s[i++]);
        }
        else if(s[i]==')'){
            while(st.top() != '('){
                res.push_back(st.top());
                st.pop();
            }
            st.pop();
            i++;
        }
        else{
            if(st.empty() || st.top() =='('){
                st.push(s[i++]);
            }
            else if(precedence(s[i]) > precedence(st.top())){
                st.push(s[i++]);
            }
            // based on associativity
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
		st=infixToPostfix(st);
		cout<<st;
	}while(t--);

	return 0;
}