#include<iostream>
#include<stack>
using namespace std;

void insertinstack(stack<int> &st,int toadd){
    if(st.empty() || st.top() <= toadd){
        st.push(toadd);
        return;
    }
    int last=st.top();
    st.pop();
    insertinstack(st,toadd);
    st.push(last);
}
void sortstack(stack<int> &st){
    if(st.size()==1)return;
    int last=st.top();
    st.pop();
    sortstack(st);
    insertinstack(st,last);
}

int main(){
    int n;
    cin>>n;
    stack<int>st;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        st.push(x);
    }
    sortstack(st);
    for(int i=0;i<n;i++){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}