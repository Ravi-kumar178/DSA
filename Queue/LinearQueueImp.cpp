
//In this queue , we can at first use the maximum available memory , but once we start popping we can't utilize that 
//empty memory unless the entire queue is empty

#include<iostream>
using namespace std;

class Queue{
    public:
     int* arr;
     int size;
     int front;
     int rear;
     
     Queue(int size){
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
     }
     
     void push(int data){
         if(front == -1 && rear == -1){
             //empty Queue
             ++rear; ++front; arr[rear] = data;
         }
         else if(rear == size-1){
             //overflow
             cout<<"Queue is full"<<endl; return;
         }
         else{
             ++rear;
             arr[rear] = data;
         }
     }
     
     void pop(){
         //empty
         //single element
         //normal
         if(front == -1 && rear == -1){
             cout<<"Queue is empty! can't pop"<<endl;
             return;
         }
         else if(front == rear){
             //single element
             arr[rear] = -1; front = -1; rear = -1;
         }
         else{
             arr[front] = -1;
             front++;
         }
     }
     
     int getSize(){
        if(rear == -1 && front == -1) return 0;
        else 
            return rear-front+1;
     }
     
     int getFront(){
        if(rear == -1 && front == -1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[front];
     }
     int getBack(){
        if(rear == -1 && front == -1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[rear];
     }
     
     void print(){
         for(int i = 0; i < size; i++){
             cout<<arr[i]<<" ";
         }
         cout<<endl;
     }
};

int main(){
    Queue q(5);
    q.print();
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.print();
    q.push(6);
    q.print();
    cout<<q.getSize()<<endl;
    cout<<q.getFront()<<endl;
    cout<<q.getBack()<<endl;
    q.print();
    q.pop();
    cout<<q.getFront()<<endl;
    cout<<q.getBack()<<endl;
    q.print();
    q.pop();
    cout<<q.getFront()<<endl;
    cout<<q.getBack()<<endl;
    q.print();
    q.pop();
    cout<<q.getFront()<<endl;
    cout<<q.getBack()<<endl;
    q.print();
    q.pop();
    cout<<q.getFront()<<endl;
    cout<<q.getBack()<<endl;
    q.print();
    q.push(7);  // memory wastage
    q.pop();
    cout<<q.getFront()<<endl;
    cout<<q.getBack()<<endl;
    q.print();
    
    cout<<q.getSize()<<endl;
    
    q.push(5);
    q.print();
    
    
}









