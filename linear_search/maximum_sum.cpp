#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long int sum=0;
    int sz=0;
    // long long int arr[n];
    int arr[n];
    for(int i=0;i<n;i++){
        long long int x;cin>>x;
        arr[i]=x;
        if(x>=0){
            sz++;
            sum+=x;
        }
    }
    if(sz==0){
        cout<<*max_element(arr,arr+n)<<" "<<1<<endl;
        return 0;
    }
    cout<<sum<<" "<<sz<<endl;
    
    return 0;
}