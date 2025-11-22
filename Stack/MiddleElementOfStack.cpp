//find middle element of stack 
#include<iostream>
#include<stack>
using namespace std;

int solve(stack<int>&st,int&pos){
    //base case
    if(pos == 1) return st.top();
    
    //1 case
    int temp = st.top();
    st.pop();
    pos--;
    
    //recursive call 
    int ans = solve(st,pos);
    
    //backtrack and fix the stack
    st.push(temp);
    return ans;
};

int getMiddleElement(stack<int>&st){
    if(st.empty()) return -1;
    int size = st.size();
    int pos = 0;
    if(size&1) pos = size/2 + 1;
    else pos = size/2;
    
    int ans = solve(st,pos);
    return ans;
}

int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    
    int ans = getMiddleElement(st);
    if(ans == -1){
        cout<<"Stack is empty"<<endl;
    }
    else cout<<"Middle element is: "<<ans<<endl;
    
    return 0;
}