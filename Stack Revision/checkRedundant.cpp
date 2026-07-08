#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool checkRedundant(string &s){
    stack<int>st;
    int i = 0;

    while(i < s.size()){
        if(s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            st.push(s[i]);

        else if (s[i] == ')'){
            int operatorCount = 0;
            while(!st.empty() && st.top() != '('){
                operatorCount += 1;
                st.pop();
            }
            if(operatorCount == 0) return true;
            st.pop();
        }
        i++;
    }
    return false;
}

int main(){
    string s = "(((a)+b)*(c+d))";
    bool isRedundant = checkRedundant(s);
    cout<<isRedundant<<endl;
    return 0;
}