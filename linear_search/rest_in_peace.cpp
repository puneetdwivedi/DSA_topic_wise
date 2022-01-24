#include<iostream>
#include<string>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE
		
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		if(n%21 ==0)cout<<"The streak is broken!";
		else {
			bool res=false;
			string st=to_string(n);
			for(int i=0;i<st.length()-1;i++){
				if(st.substr(i,2) == "21"){
					res=true;break;
				}
			}
			if(res)cout<<"The streak is broken!";
			else cout<<"The streak lives still in our heart!";
		}
		cout<<endl;
	}

	return 0;
}