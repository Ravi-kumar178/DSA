//insert in a sorted  stack 
#include<iostream>
#include<stack>
using namespace std;

void insertInSortedArray(stack<int>& st, int element){
    if(st.empty() || element > st.top()){
        st.push(element);
        return;
    }
    
    int temp = st.top();
    st.pop();
    
    insertInSortedArray(st,element);
    
    st.push(temp);
}

int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    int element = 22;
    insertInSortedArray(st,element);
    
    cout<<"Printing stack ";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}