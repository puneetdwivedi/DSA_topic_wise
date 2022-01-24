#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;


int * binary_to_int(int n){
    int *arr=new int[32];
    for(int i=0;i<32;i++){
        arr[i]=0;
    }
    int i=31;
    while(n){
        int rem=n%2;
        n/=2;
        arr[i]=rem;
        i--;
    }
    return arr;
}

int solution(int arr[],int n){
    int res=0;
    for(int i=0;i<n;i++){
        res=res^arr[i];
    }
    return res;
}

int res_xor_upto_n(int n){
    if(n%4==0)return n;
    else if(n%4==1)return 1;
    else if(n%4 == 2)return n+1;
    else return 0;
}


bool isset(int n,int i){
    int mask=1<<(i-1);
    if((n&mask) != 0)return true;
    return false;
}

int setbit(int n,int i){
    int mask=1<<(i-1);
    return (n|mask);
}

int remove_last_set_bit(int n){
    return n&(n-1);
}

int clearbit(int n,int i){
    int mask=1<<(i-1);
    mask=~mask;
    return n&mask;
}

bool ispowerof2(int n){
   return (n!=0)&& ((n&(n-1)) ==0)?true:false;
}


int totalsetbit(int n){
    int res=0;
    while(n){
        n=n&n-1;
        res++;
    }
    return res;
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    // cout<<"Hello world";

        // int n, i;cin>>n;
    // cout<<remove_last_set_bit(n);
    // cout<<solution(arr,n);
        // cout<<totalsetbit(n);
        // cout<<ispowerof2(n);
	return 0;
}