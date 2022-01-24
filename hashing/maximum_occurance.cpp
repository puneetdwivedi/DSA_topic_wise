

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main(){	

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE

	string st;
	getline(cin,st);
	unordered_map<char,int>mp;
	for(int i=0;i<st.length();i++){
		mp[st[i]]++;
	}
	char ch=mp.begin()->first;int res=mp.begin()->second;
	for(auto it=mp.begin();it != mp.end();it++){
		if(it->second > res){
			res=it->second;
			ch=it->first;
		}
		else if(it->second == res){
			if(int(it->first) < int(ch)){
				ch=it->first;
				res=it->second;
			}
		}
	}
	cout<<ch<<" "<<res<<endl;
	for(auto it=mp.begin();it != mp.end();it++)cout<<it->first<<" "<<it->second<<endl;
	cout<<st;
	return 0;
}