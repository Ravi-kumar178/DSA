#include<iostream>
#include<queue>

using namespace std;

void printQueue(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<"->";
        q.pop();
    }
    cout<<endl;
}

void reverse(queue<int>& q){
    if(q.empty()) return;
    int front = q.front();
    q.pop();
    reverse(q);
    q.push(front);
    return;
}

int main(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    cout<<"Befor reversing: "<<endl;
    printQueue(q);

    reverse(q);

    cout<<"After Reversing: "<<endl;
    printQueue(q);

    return 0;
}