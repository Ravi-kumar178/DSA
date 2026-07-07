#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int>st;
    stack<int>st2;

    st.push(2);
    st.emplace(4);
    st.push(6);

    st2.push(20);
    st2.emplace(40);
    st2.push(60);

    cout<<"size: "<<st.size()<<endl;
    cout<<"stack is empty: "<<st.empty()<<endl;
    cout<<"top ele: "<<st.top()<<endl;
    //pop ele
    st.pop();//return void
    cout<<"top ele: "<<st.top()<<endl;

    swap(st,st2);
    cout<<"top ele of st: "<<st.top()<<endl;
    cout<<"top ele of st2: "<<st2.top()<<endl;
    

}