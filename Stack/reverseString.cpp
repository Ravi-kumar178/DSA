//ravi
//print reverse of a string

#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
    string str = "ravi";
    stack<char>st;
    
    for(char ch: str){
        st.push(ch);
    }
    
    cout<<"Printing reverse of string: ";
    
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
    return 0;
}