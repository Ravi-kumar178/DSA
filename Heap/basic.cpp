#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int>pq;

    cout<<pq.empty()<<endl;

    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);
    pq.push(5);

    int size = pq.size();
    cout<<"size of heap: "<<size<<endl;
    cout<<"Is Heap empty: "<<pq.empty()<<endl;
    cout<<"Max element of heap: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Max element of heap: "<<pq.top()<<endl;

    priority_queue<int,vector<int>,greater<int>>mq;
    mq.push(1);
    mq.push(2);
    mq.push(3);
    mq.push(4);
    mq.push(5);

    cout<<mq.top()<<endl;
    mq.pop();
    cout<<mq.top()<<endl;

    return 0;
}