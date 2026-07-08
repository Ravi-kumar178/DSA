#include<iostream>
#include<stack>
using namespace std;

void insert(stack<int>& s, int ele){
    if(s.empty()){
        s.push(ele);
        return;
    }
    if(s.top() <= ele){
        s.push(ele);
        return;
    }

    int top = s.top();
    s.pop();

    insert(s,ele);

    s.push(top);
    return;
}

void print(stack<int>st){
    if(st.empty()) return;

    int top = st.top();
    st.pop();
    cout<<top<<(st.empty()?"":"->");

    print(st);
    
    return;
}

int main(){
    stack<int>s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    int ele = 25;
    insert(s,ele);
    print(s);

    return 0;
}