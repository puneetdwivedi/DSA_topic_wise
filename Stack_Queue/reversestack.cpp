#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
void insertatbottom(stack<int> &st,int tp){
    if(st.empty()){
        st.push(tp);
        return ;
    }
    int last=st.top();
    st.pop();
    insertatbottom(st,tp);
    st.push(last);
}
void revsatck(stack<int> &st){
    if(st.size() == 1)return ;
    int tp=st.top();
    st.pop();
    revsatck(st);
    insertatbottom(st,tp);
}
int main(){
    stack<int>st;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        st.push(x);
    }
    cout<<"After REVERSING "<<endl;
    revsatck(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}