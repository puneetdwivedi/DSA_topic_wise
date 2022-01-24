#include<iostream>
using namespace std;


int power_recursive(int x,int n){
    if(n==0)return 1;
    int temp=power_recursive(x,n/2);
    if((n&1) ==0)return temp*temp;
    else return x*temp*temp;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
        // cout<<"ho";
    int x,n;cin>>x>>n;
    cout<<power_recursive(x,n);

	return 0;
}