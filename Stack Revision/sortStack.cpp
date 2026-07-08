#include<iostream>
#include<stack>
using namespace std;

void insertInSortedStack(stack<int>& s, int ele){
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

    insertInSortedStack(s,ele);

    s.push(top);
    return;
}

void sort(stack<int>& s){
    if(s.empty()){
        return;
    }

    int top = s.top();
    s.pop();

    sort(s);

    insertInSortedStack(s,top);
    return;
}

void print(stack<int> s){
    if(s.empty()){
        return;
    }

    int top = s.top();
    s.pop();
    cout<<top<<(s.empty()?" ":"->");
    
    print(s);
    return;
}

int main(){
    stack<int>s;
    s.push(10);
    s.push(5);
    s.push(12);
    s.push(8);
    s.push(9);
    print(s);
    sort(s);
    cout<<endl;
    print(s);
    return 0;
}