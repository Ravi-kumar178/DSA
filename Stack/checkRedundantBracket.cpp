//find redundant
#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool checkRedundancy(string str){
    stack<char>st;
    for(char ch: str){
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        else if(ch == ')'){
            int operatorCount = 0;
            while(st.top() != '('){
                operatorCount += 1;
                st.pop();
            }
            
            if(operatorCount == 0) return true;
            st.pop();
        }
    }
    return false;
}

int main(){
    string str = "((a+b)*(c+d)+(e))";
    bool isRedundant = checkRedundancy(str);
    cout<<"Is the redundant bracket present: "<<isRedundant<<endl;
    return 0;
}