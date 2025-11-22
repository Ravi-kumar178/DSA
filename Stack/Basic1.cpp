#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int>st;
    
    st.push(1);
    st.push(3);
    st.push(5);
    
    bool isEmpty = st.empty();
    
    if(isEmpty){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }
    
    int size = st.size();
    cout<<"Size of stack st: "<<size<<endl;
    
    cout<<"Printing stack: ";
    
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    
    size = st.size();
    cout<<endl<<"Size of stack st: "<<size<<endl;
}
