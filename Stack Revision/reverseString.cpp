#include<iostream>
#include<string>
#include<stack>
using namespace std;

string reverse(string &str){
    stack<char>st;
    for(char s: str){
        st.push(s);
    };

    string s;
    while(!st.empty()){
        s.push_back(st.top());
        st.pop();
    }
    return s;
}

int main(){
    string str = "Babbar";
    string s = reverse(str);
    cout<<s<<endl;
    return 0;
}